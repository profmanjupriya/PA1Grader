[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

    SpaceRoute();  // Constructor
    - This member function is nessicary whenever a class object is being made, allowing for proper
    initialization of data.
    - Big-O complexity: O(1) becuause only two assigning operation are taking place.


    ~SpaceRoute(); // Destructor
    - The destructor is useful in the cases of deletion. The destructor dellocates memory, helping prevent memory
    leaks.
    - Big-O complexity: O(n) because the destructor has the worst case of itterating through the entire list.


    void addWaypointAtBeginning(T& data);
    - When adding a new waypoint at the beginning, we have two cases, an empty list and a nonempty list. If our
    list is empty, the new node we make will be referenced as the head and taill node. If the list contains nodes 
    already, our new node needs to point to the head/first node with its next pointer while the head points back 
    with its prev pointer, confirming the new node is at the begining the begining node.
    - Big-O complexity: O(1) because the head will always be at the beginning.


    void addWaypointAtEnd(T& data);
    - When adding a new waypoint at the end, we share the same cases as adding one in the begining. If the list is
    empty, then the new node will be added as the head and tail node becuase it is the only existing node in our
    list. If our list already contains waypoints, then we reference the new waypoint as the tail by taking the new
    waypoint's prev pointer and pointing it at the tail/last waypoint and taking that last waypoint and pointing its
    next pointer at the new waypoint.
    - Big-O complexity: O(1) because when referencing the tail, it will always be at the end.

    
    void addWaypointAtIndex(int index, T& data);
    - To add a waypoint at a specific index, a few things need are going to take place. First, if the index is 0, then
    the function to add a waypoint at the beginning is called. Next, we make our current pointer and currentCounter.
    Then, we keep track of where we are with the current node and currentCounter and then find where we insert the new
    waypoint. If our current pointer points to null and our counter is in bounds, then we are at the last index and call
    the function to add the waypoint to the end. If that does not go through, then we make our newNode, and because our
    current pointer points to the node before the desired index, we set the new node next pointer to point at the current
    node, new node prev to point at current prev, and have them point back at the new node, effectivly slotting it in position.
    - Big-O complexity: O(n) because worst case, we loop to the end of the list from the beginning.


    void removeWaypointAtBeginning();
    - To remove a way point at the begining, first we check to see if our list of destinations is empty if it is, nothing happens.
    Next we check the case where we have one destintion recorded, if so, the temp pointer will maintain our waypoints location, we
    empty our list, then delete our waypoint that temp is holdiong. If the list contains more than one waypoint, we adjust the head
    waypoint pointers and then remove it.
    - Big-O complexity: O(1) because the head will always be at the beginning.


    void removeWaypointAtEnd();
    - Similar to removing a waypoint in the beginning, we check the case for an empty list. If the list is empty, then nothing 
    happens. If there is one waypoint, we save the location, and then we empty the list, by refernecing head and tail to nullptrs,
    and then delete the waypoint. If there is more than one waypoint that exists, we save the tail waypoint location, fix the previous
    waypoint's pointers to be a valid tail, and then delete the original tail waypoint.
    - Big-O complexity: O(1) because when referencing the tail, it will always be at the end.


    void removeWaypointAtIndex(int index);
    - To remove a waypoint at an index, we need to first check if the list is empty, if so, then nothing happens. If there is one
    existing waypoint, then we call the function to remove the waypoint at the beginning. If there exists more than one waypoint, 
    then we set our temp pointer to the head waypoint. Then, while loop by checking the temp by the index to get to the index var 
    position in the list. Then check if it is out of bounds, if so nothing happens. Checks if its in the last position in the list 
    and if so, we call the remove at end function. And for all other cases, we remove the index-location waypoint by connecting the 
    adjacent waypoints to each other and then delete the node.
    - Big-O complexity: O(n) because worst case, we loop to the end of the list from the beginning.


    void traverseForward();
    - To traverse forwad in the list (print the list plans forward), we make a pointer starting at the head node (current), then
    check current to a nullptr, to end the loop at the end, and call our print function to print the current waypoint we are
    pointing at and then move current forward.
    - Big-O complexity: O(n) because worst case, we loop to the end of the list from the beginning.


    void traverseBackward();
    - To traverse backwards in the list (print the list plans backwords), we make a pointer starting at the tail node (current), then
    check current to a nullptr, to end the loop at the beginning of the list, and call our print function to print the current 
    waypoint we are pointing at and then move current backwards.
    - Big-O complexity: O(n) because worst case, we loop from the end of the list to the beginning.


    Node<T>* getWaypoint(int index);
    - To get any waypoint at any index, we make a current pointer, starting at the head. Then create a counter for our while
    loop to end at the intended index, and after moving to and keeping track of how far we move along the list, the
    position is returned.
    - Big-O complexity: O(n) because worst case, we loop to the end of the list from the beginning.


    void setWaypoint(int index, T& data);
    - To set a waypoint, after getting one from a previous function, we create a waypoint and if we have data saved from
    getWaypoint function, then we pass data through the waypoint we created.
    - Big-O complexity: O(n) because its largest time complexity is based on getWaypoint function.


    void print();
    - The print function adds the ability to print the current pointers waypoint from a conditional beginning to end, used
    in traversing forward and backward.
    - Big-O complexity: O(n) because it will loop to the end of the list from the beginning.
