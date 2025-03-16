[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)
**Constructor:**
* As it initializes head, tail, and length with simple assignment in a constant time operation. It should be Big O(1).


**Destructor:**
* Traverses and deleted all n nodes in the list. It should be Big O(n).


**Adding Waypoints:**


void addWaypointAtBeginning(T& data)
* Insert a new waypoint at the very start of the list, to make sure it becomes the first node.
* This is O(1) as it inserts a new node at head without traversal, constant time operation.


void addWaypointAtEnd(T& data)
* Appends a new waypoint at the tail of the list, making it the last node.
  void.
* This method is also O(1) because those operations are constant time operations.


void addWaypointAtIndex(int index, T& data)
* Place a waypoint at a specific position within the list, shifting existing nodes accordingly, users have to make sure the provided index is within the valid range before inserting.
* O(n), as it traverses the list up to index before inserting the node.


**Remove Waypoints:**


void removeWaypointAtBeginning()
* Eliminates the first waypoint in the list by shifting head to the next node.
* O(1) because it updates head and deletes the first node in constant time operations.


void removeWaypointAtEnd()
* Deletes the last waypoint that is located at the end of the list.
* This method is also O(1) because it updates tail and deletes the last node in constant time.


void removeWaypointAtIndex(int index)
* Allow the user to remove a waypoint at a given index, isolated it from the list.
* O(n) because the method calls getWaypoint(index), which uses a for loop to traverse up to index before deletion, making it a linear time operation.


**Traversing The Route**


void traverseForward()
* Move from the first waypoint to the last, printing each one along the way. Start from head and follow next pointers.
* O(n) because it uses a while loop to iterate from head to tail, visiting each node once, making it a linear traversal.


void traverseBackward()
* Move from the last waypoint to the first, printing waypoints from tail to head. Uses prev pointers to navigate backward through the list.
* O(n), as it uses a while loop to iterate from tail back to head, making it a linear traversal.


**Searching and Modifying Waypoints:**


Node<T>* getWaypoint(int index)
* This method returns the pointer to the Node* at the index specified index in the list.
* O(n), as it uses one for loop to traverse up to index.


void setWaypoint(int index, T& data)
* This method modifies the data in an existing waypoint without changing its position.
* O(n) because the method calls getWaypoint(index), which contains a for loop.


void print()
* Display all waypoints from first to last, move node by node and print the data stored in each.
* O(n), as it uses a while loop to iterate from head to tail, visiting every node exactly once.
