#ifndef CS210PA1_SPACEROUTE_H
#define CS210PA1_SPACEROUTE_H

#include <iostream>

using std::cout;
using std::endl;

// Node class definition
template < typename T >
  class Node {
    public: T & data;
    Node < T > * next;
    Node < T > * prev;

    Node(T & d): data(d),
    next(nullptr),
    prev(nullptr) {}
    void print() {
      cout << data << " ";
    }
  };

// SpaceRoute class definition
template < typename T >
  class SpaceRoute {
    private: Node < T > * head;
    Node < T > * tail;
    public:
      // Constructor
      SpaceRoute(): head(nullptr),
    tail(nullptr) {}

    // Destructor
    ~SpaceRoute() {
      Node < T > * current = head;
      while (current) {
        Node < T > * next = current -> next;
        delete current;
        current = next;
      }
    }

    // Insertion Operations:
    void addWaypointAtBeginning(T & data);
    void addWaypointAtEnd(T & data);
    void addWaypointAtIndex(int index, T & data);

    // Deletion Operations:
    void removeWaypointAtBeginning();
    void removeWaypointAtEnd();
    void removeWaypointAtIndex(int index);

    // Traversal Operations:
    void traverseForward();
    void traverseBackward();

    // Modification and Retrieval Operations:
    Node < T > * getWaypoint(int index);
    void setWaypoint(int index, T & data);

    // Printing:
    void print();
  };

// Inline definitions:

template < typename T >
  void SpaceRoute < T > ::addWaypointAtBeginning(T & data) {
    Node < T > * newNode = new Node < T > (data);
    if (!head) { // List is empty.
      head = tail = newNode;
    } else {
      newNode -> next = head;
      head -> prev = newNode;
      head = newNode;
    }
  }

template < typename T >
  void SpaceRoute < T > ::addWaypointAtEnd(T & data) {
    Node < T > * newNode = new Node < T > (data);
    if (!tail) { // List is empty.
      head = tail = newNode;
    } else {
      tail -> next = newNode;
      newNode -> prev = tail;
      tail = newNode;
    }
  }

template < typename T >
  void SpaceRoute < T > ::addWaypointAtIndex(int index, T & data) {
    if (index <= 0 || !head) {
      addWaypointAtBeginning(data);
      return;
    }
    Node < T > * current = head;
    int i = 0;
    while (current && i < index) {
      current = current -> next;
      i++;
    }
    if (!current) { // Index is beyond current list size.
      addWaypointAtEnd(data);
    } else {
      Node < T > * newNode = new Node < T > (data);
      Node < T > * prevNode = current -> prev;
      newNode -> next = current;
      newNode -> prev = prevNode;
      if (prevNode)
        prevNode -> next = newNode;
      current -> prev = newNode;
      if (current == head) {
        head = newNode;
      }
    }
  }

template < typename T >
  void SpaceRoute < T > ::removeWaypointAtBeginning() {
    if (!head) return;
    Node < T > * temp = head;
    head = head -> next;
    if (head)
      head -> prev = nullptr;
    else
      tail = nullptr;
    delete temp;
  }

template < typename T >
  void SpaceRoute < T > ::removeWaypointAtEnd() {
    if (!tail) return;
    Node < T > * temp = tail;
    tail = tail -> prev;
    if (tail)
      tail -> next = nullptr;
    else
      head = nullptr;
    delete temp;
  }

template < typename T >
  void SpaceRoute < T > ::removeWaypointAtIndex(int index) {
    if (index < 0 || !head) return;
    if (index == 0) {
      removeWaypointAtBeginning();
      return;
    }
    Node < T > * current = head;
    int i = 0;
    while (current && i < index) {
      current = current -> next;
      i++;
    }
    if (!current) return; // Index out-of-bounds.
    if (current == tail) {
      removeWaypointAtEnd();
      return;
    }
    Node < T > * prevNode = current -> prev;
    Node < T > * nextNode = current -> next;
    if (prevNode)
      prevNode -> next = nextNode;
    if (nextNode)
      nextNode -> prev = prevNode;
    delete current;
  }

template < typename T >
  void SpaceRoute < T > ::traverseForward() {
    Node < T > * current = head;
    while (current) {
      cout << current -> data << " ";
      current = current -> next;
    }
    cout << endl;
  }

template < typename T >
  void SpaceRoute < T > ::traverseBackward() {
    Node < T > * current = tail;
    while (current) {
      cout << current -> data << " ";
      current = current -> prev;
    }
    cout << endl;
  }

template < typename T >
  Node < T > * SpaceRoute < T > ::getWaypoint(int index) {
    Node < T > * current = head;
    int i = 0;
    while (current && i < index) {
      current = current -> next;
      i++;
    }
    return current;
  }

template < typename T >
  void SpaceRoute < T > ::setWaypoint(int index, T & data) {
    Node < T > * node = getWaypoint(index);
    if (node)
      node -> data = data;
  }

template < typename T >
  void SpaceRoute < T > ::print() {
    Node < T > * current = head;
    while (current) {
      current -> print();
      current = current -> next;
    }
    cout << endl;
  }

#endif // CS210PA1_SPACEROUTE_H