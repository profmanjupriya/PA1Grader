[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

Constructor:
It initializes the doubly linked list by setting both head and tail equals to NULL
BIG O: O(1), no loop just setting to pointers to NULL.

Destructor:
I created a new node call current and set it as head, in the while loop when current is true it will store each node to the next node and delete the current node and move on to the next one. Once it is done deleting everything, reset the head and tail equals to NULL to make sure there is no leftover pointers.
BIG O: O(n), there is a while loop used in the Destructor.

AddWayBeginning:
Created a new node with the given data at the beginning of the list. If the head is NULL, sets both head and tail to the new node, else it will change the pointers for example the new node will be the new head and the previous head will be linked to the new node.
BIG O: O(1), no loop just changing the pointers

AddWayEnd:
Created a new node with the given data at the end of the list. If tail is NULL, sets both head and tail to new node, else change the pointers like the new node will be the new tail and the previous tail will be linked to the new node.
BIG O: O(1), no loop same as the AddWayBeginning 

AddWayIndex:
This function inserts a node at the given index. If the index is 0, it will call the addWayBeginning function to add a node in the front of the list. Set a new node name current and name it head, while current is true it will keep searching and try to find that given index from index 0. If the index is out of bounds, it will add a node at the end of the list which is the use of AddWayEnd function, if the index works, it will change the pointer to insert the new node between the previous and the next node.
Big O: O(n), one while loop used in the AddWayIndex.

RemoveWayBeginning:
This function will remove the node at the beginning of the list. If the head is NULL, it will just return. Or else it updates the head to the next node and if there is a next node, it will set the prev equals to NULL, else if the list becomes empty it will set tail equals NULL.
BIG O: O(1), no loop used.

RemoveWayEnd:
This function will remove the node at the end of the list. If the tail is NULL, it will just return. Or else it will update the tail to the previous node and if there is a previous node, it sets the next of the previous node to NULL, else if the list becomes empty, it will set the head to NULL.
BIG O: O(1), no loop used.

RemoveWayIndex:
This function will remove the node at the given index. If the index is 0, it will run the RemoveWayBeginning function to remove the first node. Set a new node and named it head, while current is true it will keep searching and try to find that given index from index 0. If the node is found, it will change the previous and the next nodes to unlink the node that are been deleted.
BIG O: O(n), while loop used in the RemoveWayIndex.

Forward:
While current is true it will keep iterates till the end of the list.
BIG O: O(n), while loop is used in the Forward.

Backward:
The opposite of the Forward, it will stop iterates till the beginning of the list.
BIG O: O(n), while loop is used in the Backward.

getWaypoint:
This function will keep searching and check the current node is the given node or not. Set the currentIndex equals to 0 and let the while loop runs till it find the given node.
BIG O: O(n), while loop is used in the getWaypoint.

setWaypoint:
This function set the current node to what the data given. If current is not NUll, it will update the current to the given data.
BIG O: O(n),  due to the use of the getWaypoint so there is a while loop used.