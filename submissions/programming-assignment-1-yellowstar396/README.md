[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

### void addWaypointAtBeginning(T& data);
* Adds a waypoint at the beginning of the list
* O(1) time complexity - The operation does have any recurring operations that could be impacted by the size of the list

### void addWaypointAtEnd(T& data);
* Adds a waypoint at the end of the list
* O(1) time complexity - The operation does have any recurring operations that could be impacted by the size of the list

### void addWaypointAtIndex(T& data);
* Inserts a waypoint at a specified index
* O(n) time complexity - The method traverses through the list until reaching the specified index. On average and in the worst case, the number of operations grows linearly with the list's length (n)

### void removeWaypointAtBeginning();
* Removes the first waypoint from the list
* O(1) time complexity - The operation does have any recurring operations that could be impacted by the size of the list

### void removeWaypointAtEnd();
* Removes the last waypoint from the list
* O(1) time complexity - The operation does have any recurring operations that could be impacted by the size of the list

### void removeWaypointAtIndex(int index);
* Removes a waypoint at a specified index
* O(n) time complexity - The method traverses through the list until reaching the specified index. On average and in the worst case, the number of operations grows linearly with the list's length (n)

### void traverseForward();
* Prints all waypoints from the first to the last
* O(n) time complexity - The method iterates through each element once, so the number of operations grows linearly with the length of the list (n)

### void traverseBackward();
* Prints all waypoints in reverse order from last to first.
* O(n) time complexity - The method iterates through each element once, so the number of operations grows linearly with the length of the list (n)

### Node<T>* getWaypoint(int index);
* Retrieves a waypoint at a specified index
* O(n) time complexity - The method traverses through the list until reaching the specified index. On average and in the worst case, the number of operations grows linearly with the list's length (n)

### void setWaypoint(int index, T& data);
* Modifies the details of a waypoint at a specified index
* O(n) time complexity - The method traverses through the list until reaching the specified index. On average and in the worst case, the number of operations grows linearly with the list's length (n)

### void print();
* Displays the entire route
* O(n) time complexity - The method iterates through each element once, so the number of operations grows linearly with the length of the list (n)

### void defineFirst(T& data);
* Defines the first element in the list
* Called to add a value to an empty list
* Should only be used when the list is empty
* O(1) time complexity - The operation does have any recurring operations that could be impacted by the size of the list