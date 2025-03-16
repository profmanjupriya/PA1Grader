[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)


**addWaypointAtBeginning(T& data)** adds a node at the beginning of the doubly linked list,
if there is other nodes then the head node prev pointer points at the new node and the new node's next 
pointer points at the previous head. New node is named head of the doubly linked list.
_The Big O Complexity:_ O(1) since it will always take the same amount of time no matter how many nodes there 
are in the linked list

**addWaypointAtEnd(T& data)** adds a node at the end of the linked list by making a new node, making the tail's 
next pointer point at the new node and the new node's previous pointer point at the tail, and then naming the 
new node the new tail.
_The Big O Complexity:_ O(1) since it will always take the same amount of time no matter how many nodes there
are in the linked list

**addWaypointAtIndex(int index, T& data)** adds a node at an indicated index by first creating a temp node and 
going through the linked list until the node before the index is reached, then a new node is created and then the 
next pointer of the temp node is told to point at the new node, then the new node points at the node that previously 
followed the temp node, the temp node prev pointer is told to point at the new node and the new nodes prev pointer is 
told to point at the temp node
_The Big O Complexity:_ O(n) this is because the time it takes to complete this task depends on the index

**removeWaypointAtBeginning()** To remove a point at the beginning of the linked list we first check if the list is empty
or if there is more than 1 node. If there is more than one node, then a temp node is created and then make the next node
the head of the linked list. And lastly, the temp node is deleted it.
_The Big O Complexity:_ O(1) this is because it will take the same amount of time no matter how many nodes there are 
in the linked list 

**removeWaypointAtEnd()**To remove a point at the end of the linked list a temp node is created. The temp node becomes 
a placeholder for the current tail. The previous pointer is used to name the previous tail the tail, and then the temp 
node, which was holding the tail is deleted.
_The Big O Complexity:_ O(1) is the time complexity of this method because it will take the same amount of time no matter
how many node there are in the linked list

**removeWaypointAtIndex(int index)** starts at the head of the linked list and moves forward until it reaches the index 
that was provided, then it uses a temp node for the node that is at the index that is going to be deleted it. 
The previous node's pointer points at the node following the temp node and the previous node of that node points at the
node before the temp node, the temp node then its delete it.
_The Big O Complexity:_ O(n) this is because the time it takes to complete this task depends on the index

**traverseForward()** starts at the head of the linked list and prints the linked list from head to tail. A node named 
temp node is used to keep track of the current node. 
_The Big O Complexity:_ O(n) this is because the time it takes to complete this task depends on the length of the
linked list

**traverseBackward()** starts at the tail and uses prev pointers to read the nodes from tail to the head of the linked list
_The Big O Complexity:_ O(n) this is because the time it takes to complete this task depends on the length of the
linked list

**Node<T>* getWaypoint(int index)** starts at the head node and traverses through every node until it reaches the node
at the indicated index and return the content of the node
_The Big O Complexity:_ O(n) this is because it has to traverse through the linked list depending on the index 

**setWaypoint(int index, T& data)** changes the content of a node at an indicated index. Starts at the head node and 
goes through every node until it reaches the node that was indicated to change
_The Big O Complexity:_ O(n) Since it traverses through the linked list until it reaches the indicated index it takes and n number of time

**print()** print the content of every node in the linked list
_The Big O Complexity:_ O(n) this is because the time it takes to complete this task depends on the length of the 
linked list
