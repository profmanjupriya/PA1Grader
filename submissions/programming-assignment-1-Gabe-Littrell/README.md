[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

Constructor initializes object of the SpaceRoute class and has a time complexity of O(1)

Destructor deletes the linked list and has a time complexity of O(n) since it has to travel the length of the list

addWaypointAtBeginning adds to the head of the linked list and has a time complexity of O(1) since nothing has to be traversed

addWaypointAtEnd adds to the tail of the linked list and has a time complexity of O(1) since the tail is kept track of

addWaypointAtIndex adds a node at a specified position in the linked list and has a worst-case time complexity of O(n) since it will have to traverse the list if it isn't the head, tail, or out of bounds

removeWaypointAtBeginning deletes the head node and has a time complexity of O(1) since only the head node has to be dealt with

removeWaypointAtEnd deletes the tail node and has a time complexity of O(1) since the tail node is kept track of

removeWaypointAtIndex deletes a node at a specified index and has a worst-case time complexity of O(n) since it will have to traverse the list if it isn't the head, tail, or out of bounds

traverseForward prints the linked list from front to back using next pointers and has a worst-case time complexity of o(n) since it traverses the whole list

traverseBackward prints the linked list from back to front using prev pointers and has a worst-case time complexity of o(n) since it has to traverse the length of the list

getWaypoint retrieves a node at a specified index and has a worst-case time complexity of O(n) since the list will be traversed to find the node if it isn't at the head, tail, or out of bounds

setWaypoint sets the value of a node at a specified index and has a worst-case time complexity of O(n) since the list will be traversed to find the node if it isn't the head, tail, or out of bounds

print prints the linked list from front to back using next pointers and has a worst-case time complexity of o(n) since it traverses the whole list
