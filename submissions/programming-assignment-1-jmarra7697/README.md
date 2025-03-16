[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)


Explanation of Each Method


**void SpaceRoute<T>::addWaypointAtBeginning(T &data)**
* First checks if the list is empty. If so, creates a new head and tail node.
* If the list isn't empty, it creates a node before the head and makes the original head node come after.
* The time complexity of this method is **O(1)**, because it only contains if else statements.

**void SpaceRoute<T>::addWaypointAtEnd(T &data)**
* First checks if the list is empty. If so, creates a new head and tail node.
* If the list isn't empty, it creates a node after the tail node and makes the original tail node come before.
* The time complexity of this method is **O(1)**, because it only contains if else statements.

**void SpaceRoute<T>::addWaypointAtIndex(int index, T &data)**
* First checks if the index is at zero, and if so, call the addWaypointAtBeginning method.
* If the index is below 0, it's invalid, and the method ends.
* If the index is valid, begins a while loop function that continues until the index position is found.
* If the index goes beyond the list size, a waypoint is added at the end and the method ends.
* Creates a newNode that is inserted once the desired index is found, and makes the previous node the new node once checks are completed.
* The time complexity for this method is **O(N)**, because it may need to traverse the entire list to find the index.

**void SpaceRoute<T>::removeWaypointAtBeginning()**
* If the list is empty, nothing happens.
* Creates a node *temp*, which temporarily holds the memory of the original head node.
* If there's one node in the list, then both the head and tail become null. If not, then deletes the current head node.
* The time complexity of this method is **O(1)**, because it only contains if else statements.

**void SpaceRoute<T>::removeWaypointAtEnd()**
* If the list is empty, nothing happens.
* Creates node *temp*, which temporarily holds the memory of the original tail node.
* If there's one node in the list, then head and tail become null. If not, deletes the current tail node.
* The time complexity of this method is **O(1)**, because it only contains if else statements.

**void SpaceRoute<T>::removeWaypointAtIndex(int index)**
* If the list is empty or the index is invalid, method does nothing.
* If the index is 0, calls removeWaypointAtBeginning.
* Creates node *current*, and searches for the indexed node. If it cannot be found, does nothing. If the current is the last node, calls removeWaypointAtEnd().
* Once the index is found, connects the nodes before deleting and then deletes *current*.
* The time complexity for this method is **O(N)**, because it may need to traverse the entire list to find the index.

**void SpaceRoute<T>::traverseForward()**
* Creates node *current* and assigns it the value of the head.
* While current isn't null, prints through each value in the list. Once done, creates new line.
* The time complexity of this method is **O(N)**, because it prints out every node in the list.

**void SpaceRoute<T>::traverseBackward()**
* Creates node *current* and assigns it the value of the tail.
* While current isn't null, prints through each value in the list in reverse. Once done, creates new line.
* The time complexity of this method is **O(N)**, because it prints out every node in the list.

Node<T> *SpaceRoute<T>::getWaypoint(int index)
* If the list is empty or if the index is invalid, nothing happens.
* Creates node *current* and assigns it the value of the head, and creates a count.
* Finds the node in the index, and once found, returns the node in the index. If out of bounds, will return a nullptr instead.
* The time complexity for this method is **O(N)**, because it looks through the entire list to find the index.

**void SpaceRoute<T>::setWaypoint(int index, T &data)**
* Calls getWaypoint(index) to create a new node newNode given the index.
* If newNode is valid, it will set the new node.
* The time complexity of this method is **O(N)**, because it calls the getWaypoint function which has O(N) time complexity.