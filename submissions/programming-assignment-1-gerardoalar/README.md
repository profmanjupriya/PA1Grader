[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)
void addWaypointAtBeginning - creates a new node that attaches itself to the head of the doubly linked list and is assigned as the new head
If the list is empty, it will instead create a new node and define itself as the head and tail of the list
O(1) time complexity, doesn't iterate through the list and uses constant time operations to accomplish the method

void addWaypointAtEnd - creates a new node that attaches itself to the tail of the doubly linked list and is assigned as the new tail
If the list is empty, it will instead create a new node and define itself as the head and tail of the list
O(1) time complexity, doesn't iterate through the list and uses constant time operations to accomplish the method

void addWaypointAtIndex - utilizes the getWaypoint() method to access indexes to then insert a new node at index n, if the index to be inserted is 0 then it will utilize the addWaypointAtBeginning() method instead
O(n) time complexity, utilizes a loop to arrive to an index n in the list from the getWaypoint() method

void removeWaypointAtBeginning - uses a temp node to assign itself as the head before moving the head to the next object in the list, then deleted the temp node and assigning head->prev to point to null
O(1) time complexity, doesn't iterate through the list and uses constant time operations to accomplish the method

void removeWaypointAtEnd - uses a temp node to assign itself as the tail before moving the tail to the previous object in the list then deleting the temp node and assigning the tail->next to point to null
O(1) time complexity, doesn't iterate through the list and uses constant time operations to accomplish the method

void removeWaypointAtIndex - utilizes the getWaypoint() method to traverse the list to arrive at a certain index before deleting the specified index and connecting the list nodes. If index 0 is specified, uses the removeWaypointAtBeginning() method instead
O(n) time complexity, utilizes a loop to arrive to an index n in the list from the getWaypoint() method

void traverseForward - starts from the head node and prints the data found in the nodes in the list till it reaches the tail
O(n) time complexity, will iterate through the entire list of n objects

void traverseBackward - starts from the tail node and prints the data found in the nodes in the list till it reaches the head
O(n) time complexity, will iterate through the entire list of n objects

Node getWaypoint() uses a for loop to arrive at a specified index with index 0 being the head node. If the specified index is out of range it will return null
O(n) time complexity, utilizes a loop to arrive to an index n in the list

void setWaypoint - utlizes the getWaypoint method to locate a specific index to then update the value of the node found
O(n) time complexity, utilizes a loop to arrive to an index n in the list from the getWaypoint() method

void print - prints out the items in the list
O(n) time complexity, utilizes a loop to iterate through the entire list
