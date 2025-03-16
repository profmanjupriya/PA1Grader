[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

SpaceRoute.cpp

Line 37 : Constructor SpaceRoute() in class SpaceRoute<T> :: initializes an empty linked list setting head pointer and tail pointer to nullptr.
Time Complexity: O(1) constant time - no elements are added yet

Line 39 - Line 46: Destructor ~SpaceRoute() in class SpaceRoute<T> :: Insure the pervention of memory leaks by delleting the current node then moving on to the next node; Basically deleting all nodes starting at the head.
Time Complexity: O(n) linear time - traverses the list n number of times to delete nodes

Line 48 - Line 59: public method void addWaypointAtBeginning(T & data) in class SpaceRoute<T> :: Inserts a newNode at the begining of doubly linked list. If the list is empty, the head pointer and tail pointer = newNode, otherwise it updates the next pointer of the new node to point to the current head, the prev pointer of the current head to point to the new node, and the head pointer to the new node.
Time Complexity: O(1) constant time - Inserting at beginning of list no traversing needed.

Line 61 - Line 72: public method void addWaypointAtEnd(T & data) in class SpaceRoute<T> ::  If the list is empty the head pointer and tail pointer = newNode, otherwise it updates the next pointer of the current tail to point to the new node, the prev pointer of the new node to point to the current tail, and the tail pointer to the new node.
Time Complexity: O(1) constant time - Inserting at end of list no traversing needed just updating.

Line 74 - Line 94: public method void addWaypointAtIndex(int index, T & data) in class SpaceRoute<T>:: The function inserts a new node at a specified index in the list. If the index is 0 method addWaypointAtBeginning()is called , if it exceeds the list size method addWaypointAtEnd()is called. Otherwise, it traverses the list to update pointers and insert the node at the correct position.
Time Complexity: O(n) linear time - n is the number of nodes in the list

Line 96 - Line 103:public method void removeWaypointAtBeginning() in class SpaceRoute<T> :: Removes the first node from the list. If head node is empty nothing happens. Otherwise, head pointer points to next node, deletes the old head and updates the prev pointer of new head pointer to nullptr.
Time Complexity: O(1) constant time - Only head pointer needs to be updated

Line 105 - Line 112:public method void removeWaypointAtEnd() in class SpaceRoute<T> :: Removes the tail node form the list. If the tail node is empty nothing happens. Otherwise, tail pointer points to prev node, deletes the old tail and updates the next pointer to new tail pointer to nullptr.
Time Complexity: O(1) constant time - Only tail pointer need to be updated

Line 114 - Line 130:public method void removeWaypointAtIndex(int index) in class SpaceRoute<T> :: Removes the node at a specified index. If the index is 0, it calls method removeWaypointAtBeginning(). Otherwise, it traverses the list to the target index, updates pointers to bypass the target node, deletes the node, and updates head or tail if necessary.
Time Complexity: O(n) linear time - n is the number of nodes in the list. Must traverse the list to find the correct index.

Line 132 - line 139: public method void traverseForward() in class SpaceRoute<T> :: Iterates through the list from head to tail, printing each node.
Time Complexity: O(n) linear time - n is the number of nodes in the list. Each node must be visted once.

Line 141 - Line 148: public method void traverseBackward() in class SpaceRoute<T> :: Iterates through the list from tail to head, printing each node.
Time Complexity: O(n) linear time - n is the number of nodes in the list. Each node must be visted once.

Line 150 - Line 158:public method Node<T> *getWaypoint(int index) in class SpaceRoute<T> :: Retrieves a pointer to the node at the specified index. If the index is out of bounds, returns nullptr.
Time Complexity: O(n) linear time - n is the number of nodes in the list. Must traverse the list to find the specified index.

Line 160 - Line 165: public method void setWaypoint(int index, T & data) in class SpaceRoute<T> :: Calls method getWaypoint(index) to retrieve the node at the given index. If found, updates its data field with the provided value.
Time Complexity: O(n) linear time - n is the number of nodes in the list. Uses getWaypoint which traverse the list to find the specified index. 