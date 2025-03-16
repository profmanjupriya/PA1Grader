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

    voyagerRoute.addWaypointAtEnd(mars);
    voyagerRoute.addWaypointAtEnd(jupiter);
    voyagerRoute.addWaypointAtEnd(saturn);
    voyagerRoute.addWaypointAtBeginning(earth);
    voyagerRoute.addWaypointAtIndex(2, venus);

    // my tests of an empty list
    SpaceRoute<string> route;
    route.traverseBackward();
    route.traverseForward();
    route.removeWaypointAtIndex(8);
    route.removeWaypointAtEnd();
    route.removeWaypointAtBeginning();
    route.addWaypointAtIndex(4, venus);
    route.print();

    cout << "Voyager Route (Forward):\n";
    voyagerRoute.traverseForward();

    cout << "\nVoyager Route (Backward):\n";
    voyagerRoute.traverseBackward();

    cout << "\nPrinting Route: \n";
    voyagerRoute.print();

    voyagerRoute.removeWaypointAtIndex(2);
    cout << "\nAfter Removing Venus: \n";
    voyagerRoute.print();

    return 0;
}