#include "SpaceRoute.h"


template <typename T>
SpaceRoute<T>::SpaceRoute() { // Constructor with default setup
    head = NULL;
    tail = NULL;
}

template <typename T>
SpaceRoute<T>::~SpaceRoute() {  // Destructor deleting nodes
    Node<T> * current = head;
    while (current) {
        Node<T> * next = current -> next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
}
template <typename T>
void SpaceRoute<T>::addWaypointAtBeginning(T& data) { // creates a new node with a given data pointing the beginning of the list
    Node<T> * newNode = new Node<T>(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
}

template <typename T>
void SpaceRoute<T>::addWaypointAtEnd(T& data) { // create a new node with a given data but this is pointing the end of the list
    Node<T> * newNode = new Node<T>(data);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}

template <typename T>
void SpaceRoute<T>::addWaypointAtIndex(int index, T& data) { // inserting a node into the given index and try to find the given index from index 0
    if (index == 0) {
        addWaypointAtBeginning(data);
        return;
    }
    Node<T> * current = head;
    int num = 0;
    while (current && num < index) {
        current = current -> next;
        num++;
    }
    if (!current) {
        addWaypointAtEnd(data);
    } else {
        Node<T> * newNode = new Node<T>(data);
        newNode -> next = current;
        newNode -> prev = current -> prev;
        if (current -> prev) {
            current -> prev -> next = newNode;
        } else {
            head = newNode;
        }
        current -> prev = newNode;
    }
}

template <typename T>
void SpaceRoute<T>::removeWaypointAtBeginning() { // removes the beginning/first node
    if (!head) {
        return;
    }
    Node<T> * current = head;
    head = head -> next;
    if (head) {
        head -> prev = NULL;
    } else {
        tail = NULL;
    }
    delete current;
}

template <typename T>
void SpaceRoute<T>::removeWaypointAtEnd() { // removing the last node and set a new tail
    if (!tail) {
        return;
    }
    Node<T> * current = tail;
    tail = tail -> prev;
    if (tail) {
        tail -> next = NULL;
    } else {
        head = NULL;
    }
    delete current;
}

template <typename T>
void SpaceRoute<T>::removeWaypointAtIndex(int index) { // removing the chosen node
    if (index == 0) {
        removeWaypointAtBeginning();
        return;
    }
    Node<T> * current = head;
    int num = 0;
    while (current && num < index) {
        current = current -> next;
        num++;
    }
    if (!current) {
        return;
    }
    if (current -> prev) {
        current -> prev -> next = current -> next;
    }
    if (current -> next) {
        current -> next -> prev = current -> prev;
    } else {
        tail = current -> prev;
    }
    delete current;
}

template <typename T>
void SpaceRoute<T>::traverseForward() { // print things starts at head till the end of the list
    Node<T> * current = head;
    while (current) {
        current -> print();
        current = current -> next;
    }
    cout << endl;
}

template <typename T>
void SpaceRoute<T>::traverseBackward() { // print things starts at tail till the first of the list
    Node<T> * current = tail;
    while (current) {
        current -> print();
        current = current -> prev;
    }
    cout << endl;
}

template <typename T>
Node<T>* SpaceRoute<T>::getWaypoint(int index) { // keep searching until it gets the correct node that data wants
    Node<T> * current = head;
    int currentIndex = 0;
    while (current != NULL && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    return current;
}

template <typename T>
void SpaceRoute<T>::setWaypoint(int index, T& data) { // replace the chosen index into the given index
    Node<T> * current = getWaypoint(index);
    if (current != NULL) {
        current->data = data;
    }
}

