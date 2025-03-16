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
    string mercury = "Mercury";
    string neptune = "Neptune";

    SpaceRoute<string> voyagerRoute;

    voyagerRoute.addWaypointAtBeginning(mars);
    voyagerRoute.removeWaypointAtBeginning();
    voyagerRoute.addWaypointAtEnd(jupiter);
    voyagerRoute.removeWaypointAtEnd();
    voyagerRoute.addWaypointAtBeginning(jupiter);
    voyagerRoute.addWaypointAtBeginning(mars);
    voyagerRoute.addWaypointAtBeginning(earth);
    voyagerRoute.addWaypointAtBeginning(venus);
    voyagerRoute.addWaypointAtBeginning(mercury);
    voyagerRoute.addWaypointAtIndex(2, venus);
    voyagerRoute.removeWaypointAtIndex(2);
    voyagerRoute.addWaypointAtIndex(2, neptune);
    voyagerRoute.removeWaypointAtIndex(2);
    cout << voyagerRoute.getWaypoint(2)->data << endl;
    voyagerRoute.setWaypoint(2, neptune);

    voyagerRoute.print();
    /*
    cout << "Voyager Route (Forward):\n";
    voyagerRoute.traverseForward();

    cout << "\nVoyager Route (Backward):\n";
    voyagerRoute.traverseBackward();

    cout << "\nPrinting Route: \n";
    voyagerRoute.print();

    voyagerRoute.removeWaypointAtIndex(2);
    cout << "\nAfter Removing Venus: \n";
    voyagerRoute.print();
    */
    return 0;
}