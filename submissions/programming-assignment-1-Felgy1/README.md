[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

README

# EXPLANATION OF EACH METHOD

- addWaypointAtBeginning() method creates a new node then checks to see if the list is empty to add it as the head 
and the tail. If it is not empty, then the new node's next pointer points to the head while the head's previous
pointer points to the new node. The new node then becomes the head and the length of the list is increased.

- addWaypointAtEnd() method creates a new node then checks to see if the list is empty to add it as the head and the
tail. If it is not empty, then the tail's next pointer points to the new node while the new node's previous pointer
pointer points to the tail. The tail then becomes the new node and the length of the list is increased.

- addWaypointAtIndex() method checks to see if the inputted index is within the range of the list. Then it checks to
see if it is being inserted at the beginning or the end to simply call on the previous two methods. Else, it will
create a new node then a temporary node set to the previous index of the inputted index. Then the new node's next 
pointer will point to the temporary node's next pointer (inputted index) while its previous pointer will point to the
temporary node. Finally, the temporary node's next pointer will point to the new node successfully inserting the node at
the inputted index and the length of the list is increased.

- removeWaypointAtBeginning() method checks to see if the list is empty first. If it is not, then a temporary node is
created and set to the head. If the list only has one node then it is deleted by setting the head's and tail's pointers 
to NULL. Otherwise, the head becomes the head's next pointer, the temporary node (previous head) is deleted, and the 
length of the list is decreased.

- removeWaypointAtEnd() method checks to see if the list is empty first. If it is not, then a temporary node is created
and set to the head. If the list only had one node then it is deleted by setting the head's and tail's pointers to NULL.
Otherwise, a previous node is created and set to head. Then we traverse through the list with a while loop that runs as 
long as the temporary node's pointer points to a node. While it does the previous node is set to the temporary node and
the temporary node is set to the next node. Once the end is reached the tail is set to the previous node while the tail's
next pointer now points to NULL assigning a new tail. Finally, the temporary tail is deleted and the length of the list
is decreased.

- removeWaypointAtIndex() method checks to see if the index inputted is within the range of the list. Then it checks to
see if the waypoint being deleted is the at the beginning or the end to simply call the previous two methods. Else, it
will create a previous node set to the node before the inputted index and a temporary node set to the index. The previous
node's next pointer then points to the temporary node's next pointer and the temporary node is deleted while the length
of the list is decreased.

- traverseForward() method first checks to see if the list is empty. Then it creates a current node set to the head. To 
traverse the list it uses a while loop that runs as long as current is not a nullptr, and it prints the current node, 
then sets it to its next pointer successfully traversing the list from beginning to end.

- traverseBackward() method first checks to see if the list is empty. Then it created a current node set to the tail. To
traverse the list it uses a while loop that runs as long as current is not a nullptr, and it prints the current node,
then sets it to its previous pointer successfully traversing the list from end to beginning.

- getWaypoint() method first checks if the index inputted is withing the range of the list. Then a temporary node is 
created and set to the head. It gets the waypoint by searching the list with a for loop which sets the temporary node
to its next pointer as long as i is less than the inputted index. Once the index is found it returns it.

- setWaypoint() method creates a temporary node and sets it to the inputted index. Then it checks to see if the temporary
node is not a nullptr before setting its data to the new data inputted.

# JUSTIFICATION OF BIG O COMPLEXITIES 

- addWaypointAtBeginning() method's statements run at constant time making its Big O complexity O(1).

- addWaypointAtEnd() method's statements run at constant time making its Big O complexity O(1).

- addWaypointAtIndex() method's statements run at both constant time and O(n) because it has to traverse the list based
on what the inputted index is using the getWaypoint method or more specifically a for loop making its tightest Big O 
complexity O(n).

- removeWaypointAtBeginning() method's statements run at constant time making its Big O complexity O(1).

- removeWaypointAtEnd() method's statements run at both constant time and O(n) because it has to traverse to the list 
using a while loop which varies based on its elements (n) making its tightest Big O complexity O(n).

- traverseForward() method's statements run at both constant time and O(n) because it uses a while loop to traverse the
entire list which varies based on its elements (n) making its tightest Big O complexity O(n).

- traverseBackward() method's statements run at both constant time and O(n) because it uses a while loop to traverse the
entire list which varies based on its elements (n) making its tightest Big O complexity O(n).

- getWaypoint() method's statements run at both constant time and O(n) because it traverses the list with a for loop
based on how many elements it takes to get to the inputted index (n) making its tightest Big O complexity O(n).

- setWaypoint() method's statements run at both constant time and O(n) because it traverses the list with a for loop
  based on how many elements it takes to get to the inputted index (n) making its tightest Big O complexity O(n).


