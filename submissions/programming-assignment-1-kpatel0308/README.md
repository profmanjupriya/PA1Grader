# Space Mission Tracker

## 1. Introduction
This program implements a doubly linked list in C++ to simulate a spacecraft's mission tracker.
Each waypoint in the space mission is represented as a node, and the program allows for insertion, deletion, traversal, modification, and retrieval** of waypoints.
This project demonstrates dynamic memory management, linked list operations, and efficient data structure traversal**.


## 2. Methods & Explanations

## Insertion Operations:
void addWaypointAtBeginning(T& data);
  - Adds a waypoint at the beginning of the list.
  - Time Complexity: O(1)
- void addWaypointAtEnd(T& data);
  - Adds a waypoint at the end of the list.
  - **Time Complexity: O(1)
- void addWaypointAtIndex(int index, T& data);
  - Inserts a waypoint at the given index.
  - Time Complexity: O(n) (worst case: inserting at the end).
  Deletion Operations:
  
- void removeWaypointAtBeginning();
  - Removes the **first** waypoint in the list.
  - **Time Complexity:** O(1)
- `void removeWaypointAtEnd();`
  - Removes the **last** waypoint in the list.
  - **Time Complexity:** O(1)
- `void removeWaypointAtIndex(int index);
  - Removes the waypoint at the given index.
  - **Time Complexity:** O(n) (searching for index takes time).

### Modification & Retrieval Operations:
- `Node<T>* getWaypoint(int index);`
  - Retrieves the waypoint at the given index.
  - **Time Complexity:** O(n)
- `void setWaypoint(int index, T& data);`
  - Modifies the waypoint at the given index.
  - **Time Complexity:** O(n)

### Traversal Operations:
- `void traverseForward();`
  - Prints all waypoints from **first to last**.
  - **Time Complexity:** O(n)
- `void traverseBackward();`
  - Prints all waypoints from **last to first**.
  - **Time Complexity:** O(n)

### Printing:
- void print();
  - Displays the entire route using traverseForward().
  - **Time Complexity:** O(n)

---

## 3. Big-O Complexity Analysis
addWaypointAtBeginning() = O(1)
addWaypointAtEnd() = O(1)           
addWaypointAtIndex() = O(n)
removeWaypointAtBeginning() = O(1)           
removeWaypointAtEnd() = O(1)           
removeWaypointAtIndex() = O(n)           
getWaypoint()= O(n)           
setWaypoint()= O(n)           
traverseForward()= O(n)           
traverseBackward()= O(n)print(O(n)                                 

---
