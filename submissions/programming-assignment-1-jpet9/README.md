[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)


addWayPointAtBeginning - This method adds the given waypoint to the beginning of the double linked list.
It first checks if there is anything in the list. If not it will add the data. If there are elements, it will move the
current node to the next spot and insert new data into the head position. Then increase size.

addWaypointAtEnd - This method adds given waypoint to the end of the list.
First checks if there is a tail. If not, makes new data into head/tail. 
If there are elements, it pushes the current tail back to previous node and inserts new data as the tail. Then increases size.

addWaypointAtIndex - Adds waypoint to given index. First checks if there are elements.
Handles the bounds. Finds the element before the index. Then inserts new waypoint after the previous element. Then increases size.

removeWaypointAtBeginning - Removes first waypoint.
Checks if empty. Assigns next node from head as head. Decreases size.

removeWaypointAtEnd - Removes last waypoint.
Checks if empty. Assigns previous node of tail to tail and deletes previous tail. Size decreases.

removeWaypointAtIndex - Removes waypoint at given index.
Checks if empty. Handles bounds. Locates node before index. Checks if current next or previous need to be reassigned. Then either
Pushes forward or backward depending on which one is getting removed. Deletes waypoint and size decreases

traverseForward - starts at head and traverses forward through list.

traverseBackward - starts at tail and traverses backward through list.

getWayPoint - returns waypoint at given index. Handles index out of bounds. Traverses until reaches target waypoint. Returns waypoint.

setWayPoint - sets waypoint to given index. Handles index out of bounds. Assigns newCurr as waypoint. Sets new waypoint at index with given data.

Justification of Big O Notation: This code requires traversal and accessing the beginning, inside, and end of linked list. 
This requires O(1) and O(n) throughout the code. This is pretty cost-efficient and keeps the code effective.