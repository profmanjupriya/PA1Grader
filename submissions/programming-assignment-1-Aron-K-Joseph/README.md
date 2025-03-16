Time Complexity of all the Methods:


void addWaypointAtBeginning(T& data);:O(1) because all you do is update the head using assignment operations and one math operation for the counter

void addWaypointAtEnd(T& data);O(1)  because all you do is update the head using assignment operations and one math operation for the counter

void addWaypointAtIndex(int index, T& data);O(N) because you need to loop through most of the loop in the worst case scenario to get to the index where you need to add

void removeWaypointAtBeginning(); O(1) because all you do is update the head using assignment operations and one math operation for the counter

void removeWaypointAtEnd();O(1)  because all you do is update the head using assignment operations and one math operation for the counter

void removeWaypointAtIndex(int index); O(N) because you need to loop through most of the loop in the worst case scenario to get to the index where you need to add

void traverseForward();O(N) because you need to loop through all the elements to print each of them

void traverseBackward();O(N) because you need to loop through all the elements to print each of them

Node<T>* getWaypoint(int index); O(N) because we need to loop to the given index which in the worst case could be towards the end

void setWaypoint(int index, T& data); O(N) because I use removeWaypointAtIndex and addWaypointAtIndex which both can be O(N) making it possibly 2n but we disregard the constants so still n

void print();O(N) because you need to loop through all the elements to print each of them