import os
import subprocess
import difflib
import csv
import re
import sys

# Configuration
SUBMISSIONS_DIR = "submissions"  # Folder containing student submissions
EXPECTED_OUTPUT_FILE = "expected_output.txt"  # Reference output
CSV_OUTPUT_FILE = "grading_results.csv"  # Output CSV file
LOG_FILE = "autograder_log.txt"  # Stores full console log


class TeeLogger:
    """ Redirects all console output to both terminal and a log file. """

    def __init__(self, log_path):
        self.terminal = sys.stdout
        self.log = open(log_path, "w")

    def write(self, message):
        self.terminal.write(message)  # Print to terminal
        self.log.write(message)  # Write to log file

    def flush(self):
        self.terminal.flush()
        self.log.flush()


# Redirect output to both terminal and log file
sys.stdout = TeeLogger(LOG_FILE)


def normalize_output(text):
    """ Cleans and standardizes output formatting for comparison. """
    text = text.strip()  # Remove extra whitespace
    text = re.sub(r"\s*->\s*", " ", text)  # Replace '->' with space for uniformity
    text = re.sub(r"\s+", " ", text)  # Replace multiple spaces with a single space
    return text.lower()  # Convert to lowercase for case-insensitive comparison (optional)


def compile_and_run(student_folder):
    """ Compiles and runs the student's program. """
    try:
        os.chdir(student_folder)

        # Compile using g++
        compile_cmd = ["g++", "main.cpp", "SpaceRoute.cpp", "-o", "space_mission"]
        result = subprocess.run(compile_cmd, capture_output=True, text=True)

        if result.returncode != 0:
            return f"Compilation Failed:\n{result.stderr}", None

        # Run the compiled program
        run_cmd = ["./space_mission"]
        result = subprocess.run(run_cmd, capture_output=True, text=True)

        return None, result.stdout.strip()  # Return output
    finally:
        os.chdir(os.path.dirname(os.path.abspath(__file__)))  # Return to script directory


def compare_output(actual_output):
    """ Compares the program's output with the expected output. """
    if not os.path.exists(EXPECTED_OUTPUT_FILE):
        return "Expected output file is missing. Please generate it.", 100  # Deduct full points

    with open(EXPECTED_OUTPUT_FILE, "r") as expected_file:
        expected_output = expected_file.read().strip()

    # Normalize both outputs for comparison
    expected_output = normalize_output(expected_output)
    actual_output = normalize_output(actual_output)

    if actual_output == expected_output:
        return "Output Matches!", 0  # No deductions

    # Find differences
    diff = difflib.ndiff(expected_output.splitlines(), actual_output.splitlines())
    return "\n".join(diff), 10  # Deduct 10 points for incorrect output


def check_readme(student_folder):
    """ Checks if README.md file is present. """
    readme_path = os.path.join(student_folder, "README.md")
    if not os.path.exists(readme_path):
        return "Missing README.md (−10 points)", 10
    return "README.md Present", 0


def grade_submission(student_folder):
    """ Grades an individual student submission and returns the final score. """
    student_name = os.path.basename(student_folder)
    print(f"\nGrading {student_name}...")

    log = []
    total_deductions = 0

    # Compile and run
    compilation_error, program_output = compile_and_run(student_folder)
    if compilation_error:
        log.append(compilation_error)
        total_deductions += 100  # Full deduction for non-functional code
    else:
        output_feedback, deduction = compare_output(program_output)
        log.append(output_feedback)
        total_deductions += deduction

    # Check README
    readme_feedback, deduction = check_readme(student_folder)
    log.append(readme_feedback)
    total_deductions += deduction

    # Calculate final score
    final_score = max(0, 100 - total_deductions)
    log.append(f"Final Score: {final_score}/100")

    # Save individual grading report
    with open(os.path.join(student_folder, "grading_results.txt"), "w") as log_file:
        log_file.write("\n".join(log))

    print("\n".join(log))
    return student_name, final_score


def main():
    """ Grades all submissions and writes results to CSV. """
    results = []

    for student in os.listdir(SUBMISSIONS_DIR):
        student_path = os.path.join(SUBMISSIONS_DIR, student)
        if os.path.isdir(student_path):
            student_name, final_score = grade_submission(student_path)
            results.append((student_name, final_score))

    # Write results to CSV
    with open(CSV_OUTPUT_FILE, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["Username", "Final Score"])
        writer.writerows(results)

    print(f"\nGrading completed. Results saved in {CSV_OUTPUT_FILE}")


if __name__ == "__main__":
    main()

    # Restore normal output after script finishes
    sys.stdout.log.close()
    sys.stdout = sys.stdout.terminal