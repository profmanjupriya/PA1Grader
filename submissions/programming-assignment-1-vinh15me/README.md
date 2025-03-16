### First Method: addWaypointAtBeginning(T& data)
* What this method does is that it adds a waypoint which is data to the front of the linked list. It gets set as the head and points to what used to be the head. If there is nothing in the list, it gets set as the head and tail.
* This method has a time complexity of O(1) because it consistently takes the same amount no matter what you input.


### Second Method: addWaypointAtEnd(T& data)
* What this method does is that it adds a waypoint to the end of the linked list and that node gets set as the tail. If there is nothing in the list it get set as the head and tail.
* This method has a time complexity of O(1) because it consistently takes the same amount no matter what you input.

### Third Method: addWaypointAtIndex(int index, T& data)
* This method adds a waypoint at the index given, setting the next and prev to index +1 and index -1 respectively.
* This method has a time complexity of O(n) as the for loop runs as many times as n.

### Fourth Method: removeWaypointAtBeginning()
* This method removes a waypoint removes the waypoint at the start and sets the second node as the head.
* This method has a time complexity of O(1) because it consistently takes the same amount no matter what you input.

### Fifth Method: removeWaypointAtEnd() 
* This method removes the waypoint at the end of the list and makes the second to last node the tail
* This method has a time complexity of O(1) because it consistently takes the same amount no matter what you input.

### Sixth Method: removeWaypointAtIndex(int index) 
* This method removes a waypoint at the index given and fixes the prev and next pointers.
* This method has a time complexity of O(n) as the for loop runs as many times as n.

### Seventh Method: traverseForward() 
* This method goes and prints every element starting at the head and going all the way to the tail
* This method has a time complexity of O(n) as the for loop runs as many times as n.

### Eighth Method: traverseBackwards()
* This method goes and prints every element starting at the tail and going all the way to the head
* This method has a time complexity of O(n) as the for loop runs as many times as n.

### Ninth Method: getWaypoint(int index) 
* This method goes through the list to find a value at the index given.
* This method has a time complexity of O(n) as the for loop runs as many times as n.

### Tenth Method: setWaypoint(int index, T& _data)
* This method basic does the same as "getWaypoint" but sets the data at the node at index to the data given.
* This method has a time complexity of O(n) as the for loop runs as many times as n.
