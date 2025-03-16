[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)
addWaypointAtBeginning: O(1) because it doesn't have to loop or iterate just access the head.
addWaypointAtEnd: O(1) Same as beginning, it just accesses the tail and adds it without iterating or looping
addWaypointAtIndex: O(n) Uses the getWaypoint method which has an iterator, besides that no loops so nothing more than O(n)
removeWaypointAtBeginning: O(1) just moves the head pointer doesn't iterate or loop so O(1)
removeWaypointAtEnd: O(1) Same idea as the beginning, just moves the tail pointer doesn't iterate or loop
removeWaypointAtIndex: O(n) Uses the getWaypoint method which has an iterator, besides that no loop so nothing more than O(n)
traverseForward: O(n) loops through the entire length of the list so its O(n) just one iteration of n though so nothing more
traverseBackwards: O(n) same explanation as traverse forwards just does it backwards, both do the same thing but different directions
getWaypoint: O(n) Has an iterator that goes to the index, the index could be out of bounds and go through the entire list so O(n)
setWaypoint: O(n) Calls both removeWaypointAtIndex and addWaypointAtIndex so it would be 2n which simplifies to O(n)
print: O(n) always iterates through the entire list so is always O(n)
