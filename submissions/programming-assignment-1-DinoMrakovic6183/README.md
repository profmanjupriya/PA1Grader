addWaypointAtBeginning()
Adds a node at the head of the list. Node becomes the head and tail if the list is null.
O(1) runtime (only a few pointer updates are needed).

addWaypointAtEnd()
Adds a node at the tail of the list. Node becomes the head and tail if the list is null.
O(1) runtime (direct access to the tail allows constant time insertion).

addWaypointAtIndex()
Inserts a node at a specified index; if the index is out-of-bounds, it adds at the beginning or end.
O(n) runtime (may require traversing the list to reach the specified index).

removeWaypointAtBeginning()
Removes the node at the head of the list and updates the head pointer accordingly.
O(1) runtime (only pointer adjustments are performed).

removeWaypointAtEnd()
Removes the node at the tail of the list and updates the tail pointer accordingly.
O(1) runtime (constant time removal due to direct access to the tail).

removeWaypointAtIndex()
Removes a node at a specified index, correctly linking the neighboring nodes.
O(n) runtime (requires traversal to locate the node at that index).

traverseForward()
Prints all nodes from the head to the tail in order.
O(n) runtime (visits every node exactly once).

traverseBackward()
Prints all nodes from the tail to the head in reverse order.
O(n) runtime (visits every node exactly once in reverse).

getWaypoint()
Retrieves a pointer to the node at a specified index.
O(n) runtime (may traverse most of the list in the worst case).

setWaypoint()
Updates the data of the node at a specified index.
O(n) runtime (traversal is required to locate the node before updating).

print()
Prints the entire route by iterating through all nodes.
O(n) runtime (each node is visited once during the print operation).