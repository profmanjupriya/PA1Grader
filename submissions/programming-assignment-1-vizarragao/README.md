[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

    Explanation of each method:
    //This method adds a waypoint node at the beginning of a SpaceRoute doubly linked list 
    void addWaypointAtBeginning(T& data);
    
    //This method adds a waypoint node at the end of a SpaceRoute doubly linked list 
    void addWaypointAtEnd(T& data);
    
    //This method adds a waypoint node at a specified index of a SpaceRoute doubly linked list 
    void addWaypointAtIndex(int index, T& data);
    
    //This method deletes a waypoint node at the beginning of a SpaceRoute doubly linked list 
    void removeWaypointAtBeginning();
    
    //This method deletes a waypoint node at the end of a SpaceRoute doubly linked list 
    void removeWaypointAtEnd();
    
    //This method deletes a waypoint node at a specified index of a SpaceRoute doubly linked list 
    void removeWaypointAtIndex(int index);
    
    //This method traverses a SpaceRoute doubly linked list forwards and prints each waypoint in order
    void traverseForward();
    
    //This method traverses a SpaceRoute doubly linked list backwards and prints each waypoint in reverse order
    void traverseBackward();
    
    //This method returns the waypoint at a specified index of a SpaceRoute doubly linked list
    Node<T>* getWaypoint(int index);
    
    //This method returns the waypoint at a specified index of a SpaceRoute doubly linked list
    void setWaypoint(int index, T& data);
    
    //This method prints the waypoints of a SpaceRoute doubly linked list 
    void print(){}
    
    Justification of Big-O complexity:
    The big(O) complexity of the SpaceRoute linked list varies depending on which function is called.
    
    The access and search:
     These functions have a O(n) because in the worst case they end up traversing the whole list and running n times.
    
    Insertion/Deletion: 
    The beginning methods have a O(1) because the linked list either inputs from the head or tail which don't need to be traversed because it is a doubly linked list.
    The end methods have a O(1) because both the head and tail have two pointers so they can place nodes on either side without needing to traverse the whole linked list.
    At a specific position, the methods have a O(n) because in order to place a node a specific spot the worst case scenario would take n calls in order to complete the insertion/deletion.
