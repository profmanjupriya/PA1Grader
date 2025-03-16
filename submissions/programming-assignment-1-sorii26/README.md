[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)



there are 4 main operations that are within the program
there are the adding operations; that add nodes:
- the addWaypointAtBeginning() creates a new node with the given data and sets it at the beginning of the list
- the addWaypointAtEnd() creates a new node with the given data and sets it at the end of the linked list
- the addWaypointAtIndex() creates a new node with the given data and inserts the node at the desired specific location

there are the remove operations:
- removeWaypointAtBeginning(), is the same concept of adding a waypoint except it removes the beginning node by making node at index 1, the new head and updates the list.
- removeWaypointAtEnd(), makes the node before the end node the new tail and makes it point to null.
- with removeWaypointAtIndex(), this operation takes the given index and prompts it so the current node matches the index. Then, it deletes current and updates the list. 
there are the transversal operations: 
- transverseForward(), is used when main.cpp calls the method the first input will be the head and then sets the inputs after the previous.
- transverseBackwards(), starts at the tail and reads the data backwards.

there are the access operations: 
- getWaypoint(int index) will return a pointer to the node at the specific index.
- setWaypoint(int index, T& data) gets the node at the specified index using getWaypoint.


