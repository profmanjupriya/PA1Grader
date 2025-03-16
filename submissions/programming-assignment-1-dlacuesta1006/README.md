[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

First we have the destructor method using a while loop to go through the list deleting one by one. Big-O(n) since it go through the whole list once to delete every node
addWaypointAtBeginning method sets head and tail to a new node if empty, if not links new node with the existing head and moves head to new node. Big-O(1) it only changes some pointers, does not matter of the size of list 
addWaypointAtEnd same as Beginning sets head and tail to new node. But links the node to the existing tail and moves tail to new node. Big-O(1) because it is inserting at the tail which takes constant time.
addWaypointAtIndex, if index == 0  it calls method addWaypointAtBeginning, if not it looks through the list finding the right position, then puts in the new node, updating the next and previous pointers, then updates tail if new node is the last element. Big-O(n) is the worst case, if it is inserting near the end, we would have to go through the whole list.
removeWaypointAtIndex is similar to addWaypointAtIndex but at index == 0 calls removeWaypointAtBeginning updates next and prev pointers to remove node from list. If node is the last element it updates tail. Big-O(n) same as addWaypointAtIndex where in worst case, if it is removing near the end, we would have to go through the list.
traverseForward uses a while loop to print all the waypoints from head to tail then ends. Big-O(n) since it goes through each node
traverseBackward uses a while loop to print all the waypoints in reverse going from tail to head. Big-O(n) since it also goes through each node.
getWaypoint finds node at the given index, Gives nullptr if the index is out of bounds. Big-O(n) since there is a chance we would have to through the entire list.
setWaypoint calls getWaypoint so it can find the node at index and if the node exists it updates its data.  Big-O(n) since we are calling getWaypoint()

