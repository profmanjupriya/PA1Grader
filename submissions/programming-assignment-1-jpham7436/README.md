[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)
<h1>Programming Assignment 1!<br></h1>
<p>This project uses a doubly linked list to "manage" a spacecraft's route throughout our solar system. The test code uses strings of planet names that are passed into the doubly linked list.<br></p>

<h2>Descriptions of all edited Methods and Big-O Justificaton<br></h2>
<p>SpaceRoute() :  a constructor that sets all pointers to nullptr and length to 0. <b>Big O(1)</b> because there is no input.

<br><br>~SpaceRoute() : a destructor that deletes all pointers in the doubly linked list. <b>Big O(n)</b> where n is the number of nodes because of the while loop that traverses and destroys every Node.

<br><br>void addWaypointAtBeginning(T& data) : creates and sets a new Node as the head of the doubly linked list. <b>Big O(1)</b> because we just access and move the head pointer, no loop required.

<br><br>void addWaypointAtEnd(T& data) : creates and sets a new Node at the tail of the doubly linked list. <b>Big O(1)</b> because we just access and move the tail pointer, no loop required.

<br><br>void addWaypointAtIndex(int index, T& data) : creates and sets a new Node at a certain given index. Handles edge cases at indexes 0, length, less than 0, greater than length. <b>Big O(n)</b> where n is the number of Nodes because the worst case scenario is a traversal of every single node.

<br><br>void removeWaypointAtBeginning() : deletes the head of the doubly linked list and shifts the head pointer to the next Node. <b>Big O(1)</b> because we just access, delete, and move the head pointer, no loop required.

<br><br>void removeWaypointAtEnd() : deletes the tail of the doubly linked list and shifts the tail pointer to the previous Node. <b>Big O(1)</b> because we just access, delete, and move the tail pointer, no loop required.

<br><br>void removeWaypointAtIndex(int index) : deletes a Node at a certain index. Handles edge cases at indexes 0, length, less than 0, greater than or equal to length. <b>Big O(n)</b> where n is the number of Nodes because the worst case scenario is a traversal of every single Node.

<br><br>void traverseForward() : prints all Nodes from head to tail. <b>Big O(n)</b> where n is the number of Nodes because we are printing all Nodes using a while loop.

<br><br>void traverseBackward() : prints all Nodes from tail to head. <b>Big O(n)</b> where n is the number of Nodes because we are printing all Nodes using a while loop.

<br><br>Node<T>* getWaypoint(int index) : returns a Node at a certain index. Handles edge cases at indexes 0, length, less than 0, greater than or equal to length. <b> Big O(n)</b> where n is the number of Nodes because the worst case scenario is a traversal of every single Node.

<br><br>void setWaypoint(int index, T& data) : sets the data of a Node at a certain index. Handles edge cases at indexes 0, length, less than 0, greater than or equal to length. <b>Big O(n)</b> where n is the number of Nodes because the worst case secnario is a traversal of every single Node.

</p>
