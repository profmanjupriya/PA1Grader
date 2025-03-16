# Programming Assignment 1: Space Mission Tracker
## Method Explanations:
* void addWaypointAtBeginning(T& data)
  * adds a new waypoint to the head of the list
* void addWaypointAtEnd(T& data)
  * adds a new waypoint to the tail of the list
* void addWaypointAtIndex(int index, T& data)
  * adds a new waypoint to a specified index in the list and shifts waypoints accordingly
* void removeWaypointAtBeginning()
  * removes the first waypoint in the list
* void removeWaypointAtEnd()
  * removes the last waypoint in the list
* void removeWaypointAtIndex(int index)
  * removes a waypoint at a specified index
* void traverseForward()
  * prints all the waypoints in the list from head to tail
* void traverseBackward()
  * prints all the waypoints in the list from tail to head
* Node<T>* getWaypoint(int index)
  * returns a waypoint at a specified index
* void setWaypoint(int index, T& data)
  * changes the data of a waypoint at a specified index
* void print()
  * prints all the waypoints in the list

## Time Complexity:
* void addWaypointAtBeginning(T& data)
  * O(1)
  * head pointer has direct access to first waypoint
* void addWaypointAtEnd(T& data)
  * O(1)
  * tail pointer has direct access to last waypoint
* void addWaypointAtIndex(int index, T& data)
  * O(n)
  * loops through the list to find the index where the waypoint needs to be inserted
* void removeWaypointAtBeginning()
  * O(1)
  * head pointer has direct access to first waypoint
* void removeWaypointAtEnd()
  * O(1)
  * tail pointer has direct access to last waypoint
* void removeWaypointAtIndex(int index)
  * O(n)
  * loops through the list to find the index of the waypoint that needs to be removed
* void traverseForward()
  * O(n)
  * loops through the list to print each waypoint
* void traverseBackward()
  * O(n)
  * loops through the list backward to print each waypoint
* Node<T>* getWaypoint(int index)
  * O(n)
  * loops through the list to find a waypoint at the specified index
* void setWaypoint(int index, T& data)
  * O(n)
  * loops through the list to change the data of a waypoint at a specified index
* void print()
  * O(n)
  * loops through the list to print each waypoint
