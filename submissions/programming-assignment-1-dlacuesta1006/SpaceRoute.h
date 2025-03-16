//
// Created by Manju Muralidharan on 2/17/25.
//

#ifndef CS210PA1_SPACEROUTE_H
#define CS210PA1_SPACEROUTE_H

#include <iostream>

using namespace std;


template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr) {}
    void print() { cout << data << " "; }
};

template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    SpaceRoute() : head(nullptr), tail(nullptr) {}  // Constructor
    ~SpaceRoute(); // Destructor

    void addWaypointAtBeginning(T& data);
    void addWaypointAtEnd(T& data);
    void addWaypointAtIndex(int index, T& data);
    void removeWaypointAtBeginning();
    void removeWaypointAtEnd();
    void removeWaypointAtIndex(int index);
    void traverseForward();
    void traverseBackward();
    Node<T>* getWaypoint(int index);
    void setWaypoint(int index, T& data);
    void print(){

        Node<T>* current = head;
        while (current) {
            current->print();
            current = current->next;
        }
        cout << endl;
    }


};


#endif //CS210PA1_SPACEROUTE_H
