[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)
addWayPointAtBeginning(T& data): Inserts a node at the beginning list at the head pointer.  O(1) because we're only doing 1 condition to see whether head and tail are null, which is unrelated to the length of the list.

addWaypointAtEnd(T& data): Inserts a node at the end at the list.

addWaypointAtIndex(int index, T& data): Inserts a node at the index assigned in the list.  O(n) because the loop will go a maximum of n times and the operations are O(1).

removeWaypointAtBeginning(): Deletes a node at the beginning list at the head pointer. O(1) because we're just doing one condition to see  whether head is null or not, which is unrelated to the length of the list.

traverseForward(): Prints from beginning of the list starting from the head to the end of the list which is the tail. O(n) because the loop will go a maximum of n times and the operations are O(1).

setWaypoint(int index, T& data): Makes use of the getWaypoint function to help us get the node to be modified.  O(n) because the loop will go a maximum of n times and the operations are O(1).

print(): 