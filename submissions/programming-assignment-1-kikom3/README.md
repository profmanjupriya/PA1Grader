[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

addWaypointAtBeginning() = O(1) (if statements)
- This method first checks for an empty list and if it is not an empty list, replaces the head of the node to the new node you chose

addWaypointAtEnd() = O(1) (if statements)
- This method first checks for an empty list and if not an empty list, uses code from original singly linked list code to iterate through the list to the end and add to it

get() = O(n) (for loop)
- This was the original get method from the singly list that I implemented to also help with adding at index

addWaypointatIndex() = O(n) (get method has traversal through for loops)
- first checks for index and whether or not it is out of bounds, then checks if index is at the start where it will use addwaypointatbeginning, and also checks for if index is equal to length where it will use addwaypointatend, else it will use the get method to traverse throgh the list to insert at middle

removeWaypointAtBeginning() = O(1) (if statements)
- First checks edge case for if the list is empty, if not then makes temp node to be able to delete beginning node

removeWaypointAtEnd() = O(1) (if statements)
- Checks for empty list then if not empty deletes at end

removeWaypointAtIndex = O(n) (in the middle may have to traverse)
- first checks whether the index is out of bounds or not, then checks for empty list, after checks if the index matches the end of the list and if it does then uses removeatend statments, other than that it also checks for removing at the beginning or middle

traverseForwards = O(n) (while statement that goes on depending on list)
- starts at head and while not null, traverses through the list printing the data within each node

traverseBackwards = O(n) (prints depend on amount of nodes within list)
- starts at tail now and while not null traverses backwards, printing each node it traverses through

getWaypoint = O(n) (uses for loop that depends on list)
- checks if out of index bound and if there is a list, then goes until reaching index of the node you wanted and printing the data

setWaypoint = O(n) (for loop depending on list)
- first checks for the edge cases, with those being whether there is an empty list or index is out of bounds, then iterates through list depending on the index given adn replacing the data of said node with the data you choose

print = O(n) (goes through whole list)
- traverses through list printing data of each node