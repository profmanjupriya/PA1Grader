[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

Explanation:

    addWaypointAtBeginning(T& data) 
        Uses O(1) time complexity to add a waypoint at the beginning of the linked list
        Uses oone if/else statement and assignment operators, all O(1)
        Creates a new node, sets ->next to current head, then assigns new node to head
        Checks for if list is empty, makes new node the head and tail


    addWaypointAtEnd(T& data)
        Uses O(1), one if else statement and assignment operators
        Checks if list is empty, makes new node the head and tail
        Assigns tail->next to the new node, then makes the new node the tail


    addWaypointAtIndex(int index, T& data)
        First checks if index is less than 0 or greater than length, returns nothing 
        If index is 0, runs addWaypointAtBeginning
        Runs addWaypointAtEnd if index = length
        
        Creates temp node, iterates through list until the node right before the index
        Assigns temp->next to new node, newNode->prev to temp
        Creates tempNext, node after temp
        Assigns newNode->next to tempNext
        Checks if tempNext is nullptr before linking tempNext->prev to newNode
        
        Iterates from the head to half the list if index < length/2, and tail if greater
        However, still runs O(N)


    removeWaypointAtBeginning()
        Checks if list is empty, returns nothing
        If list is one node, deletes head 
        
        Sets head->next to be the new head, and newHead->prev = nullptr
        Deletes original head with temp variable
        Runs O(1)

    
    removeWaypointAtEnd()
        Checks if list is empty ' ' 
        Checks if list is 1 node ' ' 

        Makes tail->prev the new tail, and deletes original tail
        Makes newTail->next = nullptr
        Runs O(1)
        

    removeWaypointAtIndex(int index)
        Checks if index is less than 0, or greater than length ' '
        Checks if index is 0 ' ' 
        Checks if index = length-1 ' ' 

        Iterates to the index with temp, then creates tempNext and tempPrev
        Checks if tempNext and tempPrev is nullptr before assigning tempPrev->next to tempNext, and vice versa
        Deletes temp

        Similarly indexes half the array, but runs at O(N) 


    traverseForward()
        Checks if list is empty ' ' 
        Starts at head, traverses with temp variable, while temp doesn't equal nullptr, iterates down list, prints temp->data
        Runs O(n)

    
    traverseBackward()
        Checks if list is empty ' ' 
        starts at tail, traverses with temp variable, while temp isn't nullptr, iterates up list, prints temp->data
        Runs O(n)


    getWaypoint(int index)
        Checks if index is greater than length-1, or less than zero ' '
        Iterates to the index with temp variable
        returns temp->data

        Iterates half the list, but runs O(N)


    setWaypoint(int index, T& data)
        Checks if index is greater than length-1, or less than zero, ' ' 
        Iterates to the index with temp variable
        changes temp->data to the new data

        Iterates half the list, but runs O(N)




        

    
        


    