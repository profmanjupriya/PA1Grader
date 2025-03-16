[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)
1. addWaypointAtBeginning:

I made a new node using (new Node<T>(data))
and then check if the list is empty if so, set both head and tail to be  newNode. // O(1)

Next, if list is not empty, the newNode is linked to the current head and set the head's previous pointer to be updated to point back to newNode. // O(1)

Head pointer is newly updated to point newNode, making it the first node of the list. //O(1)

Lastly, incresae the length of the list by 1.// O(1)

Big O Notation: O(1)

This method doesn't contain any loop so it is all constant time complexity.

2. addWaypointAtEnd

I created a new node and then check if the list is empty
If so, set both head and tail to be the newNode.// O(1)

If not, connect the new node to the tail and set the previously tail node to be my newly made "newNode" previous pointer.
and set the newNode to be my new tail.// O(1)

Finally increase the length of the list by 1.//O(1)

Big O Notation: O(1)
(same like addWaypointAtBeginning)

3. addWaypointAtIndex


I check the index validity first. if index is negative number or bigger than the length of the list, I made it print "Invalid index!" //O(1)

If the index number is valid and it is 0, which means they want to add the the head place, I called addWaypointAtBeginning method.

If the index=length of the list, which means they want to add newNode at the end of the list, I called addWaypointAtEnd.

After checking the index, I finally start making a newNode.

Find previous node which is 1 index smaller than where I want to insert using getWaypoint method.// O(n)

let that node to be temp.//O(1)

Set newly inserted node to point temp node's next pointer node. And update prev pointer of my newNode to point temp node.
(since newNode is inserted in the place after the temp node, prev pointer should point temp and next pointer should point the temp node's next node) //O(1)

Also update next node's previous pointer //O(1)

Update previous node's next pointer to point newly made node.// O(1)

Finally increase the length of the list by 1. //O(1)

Big O Notation : O(n)
except finding previous node, every command line is O(1)


4. removeWaypointAtBeginning

Check if the list is empty, and if so do nothing. //O(1)

Store the head node first and check if there is only one node. If so, set both head and tail node to be NULL. // O(1)

Else case(there is more than 1 node in the list), move head to next node and set new head's prev pointer to be null. //O(1)

delete the temp node and decrease the length of the list by 1.// O(1)

Big O Notation : O(1)

5. removeWaypointAtEnd

Check if the list is empty, and if so, do nothing. // O(1)

Store the tail node using temp and then check if there is only one node. If so, set both head and tail node to be NULL. // O(1)

Else case,move tail node to previous node and set new tail node's next pointer to point NULL. //O(1)

Delete temp node and decrease the length of the list by 1. /O(1)

Big O Notation : O(1)

6. removeWaypointAtIndex

Check the index validity first. If index is negative or equal or larger than the length of the list, do nothing. //O(1)

If the list has only one node, then call removeWaypointAtBeginning(). //O(1)

If the index is equal to length-1(last index number of the list) then call removeWaypointAtEnd(). // O(1)

Else case, find the previous node by using getWaypoint(index-1) //O(n)

Set temp node to be previous node next pointer's node (get node to be deleted)// O(1)

Skip over the deleted node by pointing previous node next pointer points temp next pointer node. // O(1)

Update next node's previous pointer to point previous node. // O(1)

delete the temp node. //O(1)

Decrease the list of the length by 1. // O(1)

Big O Notation: O(n)

7. traverseForward

Set the head of the list to be temp . // O(1)

Traverse backward until reaching the null by checking if temp node is not null, then print the node data. After this move temp node to next node. // O(n)

Big O Notation : O(n)

8. traverseBackward

Set the tail of the list to be temp. //O(1)

Traverse backward until reaching NULL by checking if temp node is not null, print the node data and then move to previous node of that temp node. // O(n)

Big O Notation : O(n)

9. getWaypoint

Check the index validity first by if index is negative or equal or bigger than the length of the list, return NULL // O(1)

If they enter valid index, then set the head of the list as temp. //O(1)

To move to the desired node, using for loop to iterate their entered index time(s). During each iteration, move temp node to next node. // O(n)

Return the found temp node. // O(1)

Big O Notation : O(n)

10. setWaypoint

First, get the node at index using getWaypoint method. and set that node to be temp// O(n)

If that temp node is not null, update the data of that node to be inputted data. Then return. // O(1)

Big O Notation : O(n)

11. print

Start from the head of the list by setting head node to be current.// O(1)

Traverse through all nodes by checking if the current node is not null, print the current node data and move to the next node. // O(n)

Big O Notation : O(n)






