[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)
README Section (10 points total)
○ Explanation of each method (5 points)
○ Justification of Big-O complexity (5 points

addWayPointAtBegininng()
-Creates a new waypoint and finds and returns a pointer to the node at a specified index in a doubly linked list. 
-If the index is valid, it prints the node's data and returns the node. 
-If the index is invalid it prints "Index out of bounds" and returns nullptr.
Runtime: O(1) as we are added the waypoint the the front of the list. No traversal is needed.

addWayPointAtEnd()
-Creates a new waypoint. Checks if list is empty. If it is, new waypoint becomes head of list.
-Else waypoint is added to the end of the list.
Runtime: O(1) as we have a tail pointer constantly pointing to the tail we can instantly access the tail and add the waypoint.

addWayPointAtIndex()
-Checks if index is valid
-Handles the case where index is 0 and node is inserted at begining. Recycled code of addWayPointAtBegininng().
-Next case, index is in the middle.Traverse to node before index or until end of list. Checks if current node is in bounds.
-Insert new waypoint
Runtime:O(n) worse case the program will traverse through the entire list to insert at last index.

RemoveWaypointAtBeginning()
-Check edge case if list is empty
-Saves current head in temporary pointer. Head then points to next node.
-deletes head node
Runtime:O(1) Function does not traverse the list

RemoveWaypointAtEnd()
-Checks if list is empty
- Handles case where theres only one node in list and deletes it
- if list has more than one node it traverses to the end to delete it
- it then removes it after updating next and tail pointers
Runtime:O(n) as worst case function will traverse though entire list

removeWaypointAtIndex()
-checks if index is valid
-checks if list is empty
-handles case where index is first element. Recelyced code from RemoveWaypointAtBeginning()
-traverse the list to find the node before the node to be removed
-remove the node
Runtime(): O(n) worst case we will traverse the entire list to remove a node

traverseForward()
-first checks if the list is empty
-traverses the list and prints each node's data
Runtime: O(n) worst case will visit every node once

traverseBackward()
-checks if the list is empty
- traverses the list backwards by starting at tail and printing every nodes data once
  Runtime: O(n) worst case will visit every node once

getWaypoint()
-checks if the index is valid
-starts at head and traverses the list until index is found where it will print its data
-if the index is out of bounds an error message is printed
Runtime: O(n) worst case will visit every node once

setWaypoint()
-checks if the index is valid
-traverses the list until the index is found
- if the index is out of bounds an error message is printed
  Runtime: O(n) worst case will visit every node once