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
    voyagerRoute.removeWaypointAtBeginning();
    voyagerRoute.removeWaypointAtEnd();

     cout << "Voyager Route (Forward):\n";
    voyagerRoute.traverseForward();
     cout << "\nVoyager Route (Backward):\n";
     voyagerRoute.traverseBackward();
     cout << "\nPrinting Route: \n";
     voyagerRoute.print();
     voyagerRoute.removeWaypointAtIndex(1);
     cout << "\nAfter Removing Venus: \n";
     voyagerRoute.print();
     voyagerRoute.getWaypoint(1);
     voyagerRoute.getWaypoint(2);

     voyagerRoute.setWaypoint(1, earth);
     voyagerRoute.print();


     return 0;
}