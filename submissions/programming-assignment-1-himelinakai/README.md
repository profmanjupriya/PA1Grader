[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

Completed by Melina Kai Kwarcinski

void addWaypointAtBeginning(T& data);
    
    This function inserts a new node at the begining of the list. It updates the 
    head pointer so that it points to the new node. The new node's next pointer 
    points to the old head, and its previous pointer points to null. If the list 
    was empty, it creates the first node, which is both the head and the tail.

    The time complexity is O(1). The location of the first node is already known by head, 
    so there is no traversing needed to add the new node. All other commands have O(1) time.


void addWaypointAtEnd(T& data);
    
    This function inserts a new node at the end of the list. It updates the tail pointer so that
    it points to the new node. The new node's previous pointer points to the old tail, and 
    its next pointer points to null. If the list was empty, it creates the first node, which is 
    both the head and the tail.

    The time complexity is O(1). The location of the last node is already known by tail,
    so there is no traversing needed to add the new node. All other commands have O(1) time.

void addWaypointAtIndex(int index, T& data);
    
    This function inserts a new node at a user-specified index in the list. If the given index 
    is less than 0, or greater than the preexisting list's length, an error message will be printed.
    The new node's next pointer points to the node that was previously in the specified index.

    The time complexity is O(n). The function calls the getWaypoint() function, which traverses 
    through the list up to the given index, which could be up to the last node in the worst case 
    scenario. That yields an O(n) time complexity. Every other command in the function runs to O(1)
    so only the O(n) is considered.                         

void removeWaypointAtBeginning();

    This function removes the first node of the list. It first checks that the list is not empty
    so as to avoid any errors. If there is only one node in the list, it is deleted and the head 
    and tail point to to null. Otherwise, the second node (head->next) becomes the new head and 
    the first node is deleted.

    The time complexity is O(1). The location of the first node is already known by head, 
    so there is no traversing needed to find and delete it. All other commands have O(1) time.

void removeWaypointAtEnd();

    This function removes the last node of the list. It first checks that the list is not empty so 
    as to avoid any errors. If there is only one node in the list, it is deleted and the head and
    tail point to null. Otherwise, the second to last node (tail->prev) becomes the new tail and the
    last node is deleted.

    The time complexity is O(1). The location of the last node is already known by tail, 
    so there is no traversing needed to find and delete it. All other commands have O(1) time.
    
void removeWaypointAtIndex(int index);

    This function removes the node at a user-specified index in the list. It first checks that the
    list is not empty so as to avoid any errors. If the given index is less than 0, or greater than 
    the preexisting list's length, an error message will be printed. If the index is valid, the node
    at the given index is deleted, and the list is properly reconnected where the deleted node was. 

    The time complexity is O(n). The function calls the getWaypoint() function, which traverses 
    through the list up to the given index, which could be up to the last node in the worst case 
    scenario. That yields an O(n) time complexity. Every other command in the function runs to O(1)
    so only the O(n) is considered.

void traverseForward();

    This function traverses through the entire linked list from the first node to the last, printing
    the data value in each as it does. It does check if the list is empty and outputs a message if it
    is. 

    The time complexity is O(n). The function is responsible for outputting the data belonging to each node 
    in the list, which means it must traverse through the entire length of it, which yields O(n). 

void traverseBackward();

    This function traverses through the entire linked list from the last node to the first, printing
    the data value in each as it does. It does check if the list is empty and outputs a message if it
    is.

    The time complexity is O(n). The function is responsible for outputting the data belonging to each node 
    in the list, which means it must traverse through the entire length of it, which yields O(n). 

Node<T>* getWaypoint(int index);

    This function returns the address of the node at a user-specified index within the list, if the index
    is valid. It checks if the list is empty, outputs a message if it is and returns null. If the given 
    index is less than 0, or greater than the preexisting list's length, an error message will be printed 
    and null will be returned. 

    The time complexity is O(n). The function traverses through the list up to the given index, which could 
    be up to the last node in the worst case scenario. That yields an O(n) time complexity.

void setWaypoint(int index, T& data);

    This function finds the node at a user-specified index within the list, and updates its data value to 
    the new data imputed by the user, if it is a valid node in the list. It checks if the list is empty, 
    and outputs a message if it is. If the given index is less than 0, or greater than the preexisting list's 
    length, an error message will be printed. 

    The time complexity is O(n). The function calls the getWaypoint() function, which traverses 
    through the list up to the given index, which could be up to the last node in the worst case 
    scenario. That yields an O(n) time complexity. Every other command in the function runs to O(1)
    so only the O(n) is considered.  

void print();

    This function traverses through the list and prints the data value of every node. It checks if the
    list is empty and prints a message if it is. 

    The time complexity is O(n). The function is responsible for outputting the data belonging to every node 
    in the list, which means it must traverse through the entire length of it, which yields O(n). 
