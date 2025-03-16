[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

Must include explanations of each method and how they work. 
Then, for each method, calculate the Big O notation.

Runtime:
Constructor: SpaceRoute O(1)
    The runtime of the constructor is simply O(1) as it just initializes the pointers and length of the list, which is a constant
    time operation.

Destructor: ~SpaceRoute O(n)
    The runtime of the SpaceRoute destructor is O(n) as it traverses through each planet and deletes it. This function
    is like the government canceling the mission for the team. Or, in the case of a dystopia, deleting the mission events from
    ever seemingly like they occurred.

Function #1: addWaypointAtBeginning O(1)
    - The runtime of this function is O(1) because we are inserting a waypoint at the
        beginning of an empty list. There are no later waypoints that require shifting to the list.

Function #2: addWaypointAtEnd O(1)
    The runtime of this function is also O(1) because we are inserting a waypoint at the
    end of a list. All that this means for a Doubly Linked List is that node is added, receiving
    a pointer from the prev last node and now the head also gets a pointer from the tail. This method means
    that a new celestial waypoint has been reached in the journey, requiring the list to increase with the journey size.

Function #3: addWaypointAtIndex O(n)
    The runtime of addWaypointAtIndex is O(n) because the index must be traversed through each consecutive point
    until the index is reached. This function is used for adding waypoints to the journey (element to a list) at a specified point. 
    This function allows for the command team to make journey stops and additions throughout the mission incase they forgot to insert it 
    into the mission plans in the beginning.

Function #4: removeWaypointAtBeginning O(1)
    The function, removeWaypointAtBeginning, has a runtime of O(1). Since the first node is being removed, all that changes
    is the pointer in which the tail node is pointing to. Same goes for the new head, which is head -> next. Essentially what this means
    is that the command team is removing the original start point.

Function #5: removeWaypointAtEnd O(1)
    This function is similar to the previous function. The runtime is O(1) because we are just deleting the last node, or planet, 
    and setting the head prev pointer equal to the index of an element at tail - 1. This function allows for the command team to delete
    a waypoint from the end of their journey.

Function #6: removeWaypointAtIndex O(n)
    The runtime of removeWaypointAtIndex is O(n) because the doubly linked list must be traversed for the specified element to be accessed.
    Once accessed, the operation of deletion is O(1), but since O(n) > O(1), the runtime is O(n). This operation can be used by the command team
    to remove specified stops along their trip.

Function #7: traverseForward O(n)
    The runtime of traverseForwad is O(n) because every planet in the list must be accessed and printed. The command team can use this operation
    for viewing what their journey has looked like from the start to see how far they have come.

Function #8: traverseBackward O(n)
    The runtime of traverseBackwards is O(n) because every planet in the list must be accessed and printed. The command team
    can use this operation to see, in reverse, the journey they have been on, from where they are at now to where they started at the end of the list.

Function #9: getWaypoint O(n)
    The runtime of getWaypoint is O(n) because the command team must go through each planet in their list to see where the current planet
    they are at now. 

Function #10: setWaypoint O(n)
    The runtime of setWaypoint is O(n) because it calls getWaypoint at the index specified. Since getWaypoint has a runtime of O(n),
    this operation must abide to the runtime of getWaypoint. This function is used for setting a new waypoint in the journey, or 
    in layman's terms, marking down the current planet that the team is touching down on.

Function #11: print O(n)
    Print is a different function from the rest of the program. This is because it is simply
    printing the list, not necessarily performing operations on the data. The runtime of print is
    simply O(n) because it has to go through the specified length of the journey.