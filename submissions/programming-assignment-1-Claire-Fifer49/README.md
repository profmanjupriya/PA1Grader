[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

### void addWaypointAtBeginning(T& data);
This method creates a Waypoint with the given data and adds it to the beginning of the list. This method can handle an empty list. The method has a time efficiency of **O(1)** because there is no traversal needed.

### void addWaypointAtEnd(T& data);
This method creates a Waypoint with the given data and adds it to the end of the list. This method can handle an empty list. The method has a time efficiency of **O(1)** because there is no traversal needed.

### void addWaypointAtIndex(int index, T& data);
This method creates a Waypoint with the given data and adds it at the given index of the list. This method can handle an empty list. The method has a time efficiency of **O(n)** because a loop depending on the length of the list is needed.

### void removeWaypointAtBeginning();
This method removes and deletes from memory the first Waypoint of the list. If the list is empty nothing occurs. The method has a time efficiency of **O(1)** because there is no traversal needed.

### void removeWaypointAtEnd();
This method removes and deletes from memory the last Waypoint of the list. If the list is empty nothing occurs. The method has a time efficiency of **O(1)** because there is no traversal needed.

### void removeWaypointAtIndex(int index);
This method removes and deletes from memory the Waypoint at the specified index of the list. If the list is empty nothing occurs. The method has a time efficiency of **O(n)** because a loop depending on the length of the list is needed.

### void traverseForward();
This method prints the list out on one line from front to back. The method has a time efficiency of **O(n)** because a loop depending on the length of the list is needed.

### void traverseBackward();
This method prints the list out on one line from back to front. The method has a time efficiency of **O(n)** because a loop depending on the length of the list is needed.

### Node<T>* getWaypoint(int index);
This method returns the Node at the given index. If the list is empty or the index is out of bounds, nullptr is returned. The method has a time efficiency of **O(n)** because a loop depending on the length of the list is needed.

### void setWaypoint(int index, T& data);
This method updates the existing Node at the given index with the given data. The method has a time efficiency of **O(n)** because a loop depending on the length of the list is needed.
