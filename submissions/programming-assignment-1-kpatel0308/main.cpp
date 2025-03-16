#include <iostream>
#include <string>
#include "SpaceRoute.cpp"  // Include the SpaceRoute class definition

using namespace std;

int main() {
    string mars = "Mars";
    string jupiter = "Jupiter";
    string saturn = "Saturn";
    string earth = "Earth";
    string venus = "Venus";

    SpaceRoute<string> voyagerRoute;

    // Adding waypoints to the route
    voyagerRoute.addWaypointAtEnd(mars);
    voyagerRoute.addWaypointAtEnd(jupiter);
    voyagerRoute.addWaypointAtEnd(saturn);
    voyagerRoute.addWaypointAtBeginning(earth);
    voyagerRoute.addWaypointAtIndex(2, venus);

    // Traversing the route forward and backward
    cout << "Voyager Route (Forward):\n";
    voyagerRoute.traverseForward();

    cout << "\nVoyager Route (Backward):\n";
    voyagerRoute.traverseBackward();

    // Printing the full route
    cout << "\nPrinting Route: \n";
    voyagerRoute.print();

    // Removing a waypoint
    voyagerRoute.removeWaypointAtIndex(2);
    cout << "\nAfter Removing Venus: \n";
    voyagerRoute.print();

    return 0;
}