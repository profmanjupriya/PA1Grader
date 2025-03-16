**Explanation of each method:**

void addWaypointAtBeginning(T& data) 
- This method adds a celestial waypoint at the beginning of the doubly linked list.

void addWaypointAtEnd(T& data) 
- This method adds a celestial waypoint at the end of the doubly linked list.

void addWaypointAtIndex(int index, T& data) 
- This method allows the user to insert a celestial waypoint at a specified index, contingent on the fact that the index is not out of bounds.

void removeWaypointAtBeginning() 
- This method deletes the celestial waypoint located at the front of the doubly linked list.

void removeWaypointAtEnd() 
- This method deletes the celestial waypoint located at the end of the doubly linked list.

void removeWaypointAtIndex(int index) 
- This method allows the user to delete a celestial waypoint at any given, valid, index.

void traverseForward() 
- This method traverses all the celestial waypoints in the doubly linked list, printing each waypoint as it passes it. Prints from the front of the list to the back of the list.

void traverseBackward() 
- This method traverses all the celestial waypoints in the doubly linked list, printing each waypoint as it passes it. Prints from the back of the list to the front of the list.

Node<T>* getWaypoint(int index) 
- This method returns the Node* of any valid index in the list entered by the user.

void setWaypoint(int index, T& data) 
- This method allows a user to access the Node* at any valid index and modify its data.

void print() 
- This method prints the entire celestial route.

--

**Justification of Big-O Complexity:**

void addWaypointAtBeginning(T& data) - O(1)
- Keeping track of the head node pointer allows insertion at the front of a doubly linked list to be a constant time operation.

void addWaypointAtEnd(T& data) - O(1)
- Keeping track of the tail node pointer allows insertion at the end of a doubly linked list to be a constant time operation.

void addWaypointAtIndex(int index, T& data) - O(N)
- This method utilizes the 'getWaypoint' method which turns insertion at any valid index into a linear time operation.

void removeWaypointAtBeginning() - O(1)
- Keeping track of the head node pointer allows deletion at the front of a doubly linked list to be a constant time operation.

void removeWaypointAtEnd() - O(1)
- Keeping track of the tail node pointer allows deletion at the end of a doubly linked list to be a constant time operation.

void removeWaypointAtIndex(int index) - O(N)
- This method utilizes the 'getWaypoint' method which turns deletion at any valid index into a linear time operation.

void traverseForward() - O(N)
- This method traverses the entire list from front to back making it a linear time operation.

void traverseBackward() - O(N)
- This method traverses the entire list from back to front making it a linear time operation.

Node<T>* getWaypoint(int index) - O(N)
- This method traverses the list until it reaches a specified index making it a linear time operation.

void setWaypoint(int index, T& data) - O(N)
- This method has to traverse the list up until a specified index in order to access the Node* and modify its data, making it a linear time operation.

void print() - O(N)
- This method traverses the entire list from front to back making it a linear time operation.