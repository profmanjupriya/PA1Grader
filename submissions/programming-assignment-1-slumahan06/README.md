[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

○ Explanation of each method (5 points)
○ Justification of Big-O complexity (5 points)

1. addWayPointAtBeginning()

   This function creates a new node with the given data. It sets the next pointer of the new node to the existing head, and then sets the head pointer to the new node. Increases the length of the list by one.

   This function has a time complexity of O(1) since instead of iterating through the entire list, it utilizes the existing head pointer to add to the start of the route.
-----
2. addWayPointAtEnd()
   
   The function first checks if the list is empty and calls addWayPointAtBeginning() if true. If not, a new node is created with the data. The existing tail's next pointer is linked to the new node and the prev pointer of the new node is linked to the old tail. The tail pointer is then set to the new node and the length is increased.

   This function has a time complexity of O(1) since there is no iteration that would result in anything greater. The tail pointer is used as a starting point and all commands have a constant time complexity.
-----
3. addWayPointAtIndex()

   If the given index is 0, addWayPointAtBeginning() is called and if it is at the end of the current route, addWayPointAtEnd() is called. Otherwise, a new Node is created. The nodes at and before the given index are recorded, and the prev and next pointers for the three Node pointers are modified to fit in the new Node.

   Generally, this function has a time complexity of O(n), since it calls the getWaypoint() function which iterates through the route until it finds the correct index, which is O(n).
-----
4. removeWayPointAtBeginning()

   If the list is not empty, a temporary Node pointer is created that points to head. The head pointer is moved to the next item in the list, and the Node that temp points to is deleted.

   The time complexity for this is O(1) since it uses the head pointer to find the correct item to remove rather than iterating through the list.
-----
5. removeWayPointAtEnd()

   If the list is not empty, the function creates a temporary Node pointer at tail. The tail pointer is moved to the previous node and the temporary pointer is deleted.

   This function also has a time complexity of O(1) as it relies on the tail pointer to identify the correct item to remove instead of using a loop to go to the end of the list.
-----
6. removeWayPointAtIndex()

   If the given index is 0, removeWayPointAtBeginning() is called and if it is the last item in the list, removeWayPointAtEnd() is called. Otherwise, a temporary Node pointer is created at the given index and the items before and after it are identified. The next and prev pointers of these two surrounding items are connected to each other and the pointer at the index is deleted.

   The time complexity here is O(n) since the function getWaypoint() is called which iterates through the route until finding the correct index.
-----
7. traverseForward()
   
   Creates a pointer to the head node and traverses through the entire list, printing the data at each index and moving down.

   The time complexity here is O(n) since the function requires a loop to traverse through the entire route.
-----
8. traverseBackward()

   Creates a pointer at the tail node and traverses the route backwards, printing the data at each index and moving up.
   
   The time complexity is also O(n) since a loop is used to traverse through all the elements in the list.
-----
9. getWaypoint()

   If the given index is valid, a temporary pointer is created at head. It keeps moving the pointer through the list until arriving at the given index.
   
   Here, the time complexity is O(n) since a loop is used to go through a number of elements until the correct index is found.
-----
10. setWaypoint()

   If the given index is valid and the list is not empty, the correct item is located and its data is changed accordingly.

   The time complexity is O(n) since it requires the getWaypoint() function to loop through the route and return the item at the correct index.

-----
11. print()

   Starts at the head node and moves down the list, printing the data at each index until reaching the end of the list.

   The time complexity is O(n) because the function iterates through the entire route one step at a time until reaching the end.

-----
The constructor sets the head and tail pointers to NULL and the length of the route to 0. The destructor starts at the head, creates a temporary pointer, moves the head by one, and destroys the temporary pointer. It does this until the entire route is deleted.

