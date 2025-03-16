#include "SpaceRoute.h"

#include <iostream>
#include <string>
using namespace std;

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string& n, double d, const string& log);
    const string& getName() const;
    double getDistance() const;
    const string& getMissionLog() const;
    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};



template <typename T>
SpaceRoute<T>::~SpaceRoute() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current -> next;
        delete current;
        current = next;
    }
}

template<typename T>
void SpaceRoute<T>::addWaypointAtBeginning(T &data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
}

template<typename T>
void SpaceRoute<T>::addWaypointAtEnd(T &data) {
    Node<T>* newNode = new Node<T>(data);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail -> next = newNode;
        tail -> prev = tail;
        tail = newNode;
    }
}

template<typename T>
void SpaceRoute<T>::addWaypointAtIndex(int index, T &data) {
    if (index == 0) {
        addWaypointAtBeginning(data);
        return;
    }
    Node<T>* current = head;
    int count = 0;
    while (current != nullptr && count < index - 1) {
        current = current -> next;
        count++;
    }
    if (current == nullptr) return;
    Node<T>* newNode = new Node<T>(data);
    newNode -> next = current -> next;
    if (current -> next != nullptr) {
        current -> next -> prev = newNode;
    }
    current -> next = newNode;
    newNode -> prev = current;
    if (newNode -> next == nullptr) {
        tail = newNode;
    }
}

template<typename T>
void SpaceRoute<T>::removeWaypointAtBeginning() {
    if (head == nullptr) return;
    Node<T>* temp = head;
    head = head -> next;
    if (head != nullptr) head -> prev = nullptr;
    else tail = nullptr;
    delete temp;
}

template<typename T>
void SpaceRoute<T>::removeWaypointAtEnd() {
    if (tail == nullptr) return;
    Node<T>* temp = tail;
    tail = tail -> prev;
    if (tail != nullptr) tail -> next = nullptr;
    else head = nullptr;
    delete temp;
}

template<typename T>
void SpaceRoute<T>::removeWaypointAtIndex(int index) {
    if (index == 0) {
        removeWaypointAtBeginning();
        return;
    }
    Node<T>* current = head;
    int count = 0;
    while (current != nullptr && count < index) {
        current = current -> next;
        count++;
    }
    if (current == nullptr) return;
    if (current -> prev != nullptr) {
        current -> prev -> next = current -> next;
    }
    if (current -> next != nullptr) {
        current -> next -> prev = current -> prev;
    }
    if (current == tail) {
        tail = current -> prev;
    }
    delete current;
}

template<typename T>
void SpaceRoute<T>::traverseForward() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout<< current -> data << " -> ";
        current = current -> next;
    }
    cout << "Finished" << endl;
}

template<typename T>
void SpaceRoute<T>::traverseBackward() {
    Node<T>* current = tail;
    while (current !=nullptr) {
        cout << current -> data << " <- ";
        current = current -> prev;
    }
    cout << "Started" << endl;
}

template<typename T>
Node<T> *SpaceRoute<T>::getWaypoint(int index) {
    Node<T>* current = head;
    int count = 0;
    while (current != nullptr && count < index) {
        current = current -> next;
        count++;
    }
    return current;
}

template<typename T>
void SpaceRoute<T>::setWaypoint(int index, T &data) {
    Node<T>* current = getWaypoint(index);
    if (current != nullptr) {
        current -> data = data;
    }
}

















