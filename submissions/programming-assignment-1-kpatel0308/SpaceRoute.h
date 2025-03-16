#ifndef SPACEROUTE_H
#define SPACEROUTE_H

#include <iostream>

// Node class declaration
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T d);  // Constructor
    void print();  // Helper method to print node data
};

// SpaceRoute class declaration
template <typename T>
class SpaceRoute {
private:
    Node<T>* head;  // Pointer to the head (first waypoint)
    Node<T>* tail;  // Pointer to the tail (last waypoint)

public:
    SpaceRoute();  // Constructor
    ~SpaceRoute();  // Destructor

    void addWaypointAtBeginning(T& data);
    void addWaypointAtEnd(T& data);
    void addWaypointAtIndex(int idx, T& data);
    void removeWaypointAtBeginning();
    void removeWaypointAtEnd();
    void removeWaypointAtIndex(int idx);
    void traverseForward();
    void traverseBackward();
    Node<T>* getWaypoint(int idx);
    void setWaypoint(int idx, T& data);
    void print();  // Print the entire route
};

#endif