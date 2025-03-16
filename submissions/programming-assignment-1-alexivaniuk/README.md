[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

Constructor:
- O(1), as it is only initializing variables, which is a constant time operation

Destructor:
- O(n), as it goes through the entire list to delete each node

addWaypointAtBeginning:
- If the list is empty, it sets both head and tail to newNode, since there is only one element in the list. If the list is not empty, it sets newNode's next to head, head's prev to newNode, and newNode to head
- This is O(1), as all of these operations are constant time operations

addWaypointAtEnd:
- If the list is empty, does the same as adding to beginning. If it is not empty, sets newNode prev to tail, tail next to newNode, and tail to newNode.
- O(1), as these are all constant time operations

addWaypointAtIndex:
- Creates a temp node and uses a loop to set it to the node previous of the specified index. Sets newNode's next to temp next, newNode's prev to temp, temp next prev to newNode, and temp next to newNode
- O(n), as it uses a loop to get the previous node of the specified index

removeWaypointAtBeginning:
- If list is not empty and greater than 1, sets a temp node to head, moves head to head next, deletes temp, and sets head prev to null
- O(1), as these are all constant time operations

removeWaypointAtEnd:
- If list is not empty and greater than 1, sets temp to tail, tail to tail prev, deletes temp, and sets tail next to null
- O(1), as these are all constant time operations

removeWaypointAtIndex:
- Similar to adding, sets temp to previous node, create newNode as the one to delete, temp next to newNode next, newNode next prev to temp, and deletes newNode
- O(n), as it uses a loop to find the previous node of the specified index

traverseForward:
- uses a loop to print each node in the list starting at the head
- O(n), as it uses a loop to go through each node

traverseBackward:
- Same as forward but starts at tail
- O(n), uses loop to go through each node

getWaypoint:
- uses loop to find and return specified index
- o(n), uses loop to go through each node

setWaypoint:
- uses loop to find specified index and set its data to specified argument
- O(n), uses loop to find specified index

print:
- goes through each node and prints it
- O(n), uses loop to go through each node
