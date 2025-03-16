//
// Created by Manju Muralidharan on 2/17/25.
//

#ifndef CS210PA1_SPACEROUTE_H
#define CS210PA1_SPACEROUTE_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T d) : data(d), next(nullptr), prev(nullptr) {}

    void print() {
        cout << data << " ";
    }
};


template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;

public:
    SpaceRoute();
    ~SpaceRoute();

    void addWaypointAtEnd(T data);
    void addWaypointAtBeginning(T data);
    void addWaypointAtIndex(int index, T data);
    void removeWaypointAtEnd();
    void removeWaypointAtBeginning();
    void removeWaypointAtIndex(int index);
    void traverseForward();
    void traverseBackward();
    void print();
};


template <typename T>
SpaceRoute<T>::SpaceRoute() : head(nullptr), tail(nullptr), length(0) {}

template <typename T>
SpaceRoute<T>::~SpaceRoute() {
    Node<T>* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template <typename T>
void SpaceRoute<T>::addWaypointAtEnd(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (length == 0) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
}

template <typename T>
void SpaceRoute<T>::addWaypointAtBeginning(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (length == 0) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}

template <typename T>
void SpaceRoute<T>::addWaypointAtIndex(int index, T data) {
    if (index < 0 || index > length) {
        cout << "Invalid index!" << endl;
        return;
    }
    if (index == 0) {
        addWaypointAtBeginning(data);
        return;
    }
    if (index == length) {
        addWaypointAtEnd(data);
        return;
    }

    Node<T>* newNode = new Node<T>(data);
    Node<T>* temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    length++;
}

template <typename T>
void SpaceRoute<T>::removeWaypointAtBeginning() {
    if (length == 0) return;
    Node<T>* temp = head;
    if (length == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    length--;
}

template <typename T>
void SpaceRoute<T>::removeWaypointAtEnd() {
    if (length == 0) return;
    Node<T>* temp = tail;
    if (length == 1) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    length--;
}

template <typename T>
void SpaceRoute<T>::removeWaypointAtIndex(int index) {
    if (index < 0 || index >= length) return;
    if (index == 0) {
        removeWaypointAtBeginning();
        return;
    }
    if (index == length - 1) {
        removeWaypointAtEnd();
        return;
    }

    Node<T>* prevNode = head;
    for (int i = 0; i < index - 1; i++) {
        prevNode = prevNode->next;
    }
    Node<T>* temp = prevNode->next;

    prevNode->next = temp->next;
    temp->next->prev = prevNode;

    delete temp;
    length--;
}

template <typename T>
void SpaceRoute<T>::traverseForward() {
    Node<T>* temp = head;
    while (temp) {
        temp->print();
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
void SpaceRoute<T>::traverseBackward() {
    Node<T>* temp = tail;
    while (temp) {
        temp->print();
        temp = temp->prev;
    }
    cout << endl;
}

template <typename T>
void SpaceRoute<T>::print() {
    traverseForward();
}
#endif //CS210PA1_SPACEROUTE_H
