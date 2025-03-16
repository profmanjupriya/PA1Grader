[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

addWayPointAtBeginning (T& data) simply adds a node to the start and has a time complexity of O(1)

addWayPointAtEnd(T& Data) adds a node to the end and also has a time complexity of O(1)

addWaypointAtIndex(int index, T& Data) inserts a node at a specific index and has a time complexity of O(n)

removeWaypointAtBeginning() removes the first node and has a time complexity of O(1)

removeWaypointAtEnd() removes the node at the tail and also has a time complexity of O(1)

removeWaypointAtIndex(int index) looks for a node at a specific index and removes it, having a time complexity of O(n)

traverseForward() prints the list starting from the front to the back with a time complexity of O(n)

traverseBackward prints the list in descending order and also has a time complexity of O(n)

getWaypoint(int index) is a getter used to retrieve a node at a given index with a time complexity of O(n)

setWaypoint is a setter that updates a node at a specific index and also has a time complexity of O(n)

print() just prints all the waypoints listed on a given route and has a time complexity of O(n)

SpaceRoute() is a constructor that initializes an empty list O(1)

~SpaceRoute is a destructor that deallocates all the memory inside the nodes and has a time complexity of O(n)

Node(const T& d) is a constructor that initializes a node with a time complexity of O(1)