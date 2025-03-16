#include <iostream>
#include <string>
#include "SpaceRoute.cpp"

using namespace std;

int main() {
    string mars = "Mars";
    string jupiter = "Jupiter";
    string saturn = "Saturn";
    string earth = "Earth";
    string venus = "Venus";

    SpaceRoute<string> voyagerRoute;

    voyagerRoute.addWaypointAtEnd(mars); // Now getting infinite list.
    voyagerRoute.addWaypointAtEnd(jupiter); // Using breakpoint: we see t0x600002c19220 instead of Mars. Fix needed.
    voyagerRoute.addWaypointAtEnd(saturn); // Fix: instead of data, we use node as node is indicative of a singular item in a list.
    voyagerRoute.addWaypointAtBeginning(earth);
    voyagerRoute.addWaypointAtIndex(2, venus);

    cout << "Voyager Route (Forward):\n"; // not printing the traverse forward, cutting off rest of program.
    voyagerRoute.traverseForward();

    cout << "\nVoyager Route (Backward):\n";
    voyagerRoute.traverseBackward();

    cout << "\nPrinting Route: \n";
    voyagerRoute.print();

    voyagerRoute.removeWaypointAtIndex(2);
    cout << "After Removing Venus: \n";
    voyagerRoute.print();

    voyagerRoute.removeWaypointAtBeginning(); // good up to here
    cout << "\nAfter removing Earth" << endl;
    voyagerRoute.print();

    voyagerRoute.removeWaypointAtEnd(); // last function in need of correction
    cout << "\nAfter removing Saturn" << endl;
    voyagerRoute.print();

    return 0;
}