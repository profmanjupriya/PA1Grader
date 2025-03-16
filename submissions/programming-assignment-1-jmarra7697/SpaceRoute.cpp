#include <iostream>
#include <string>
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
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;


public:
    SpaceRoute(); // Constructor
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

// constructor
template <typename T>
SpaceRoute<T>::SpaceRoute() {
    head = nullptr;
    tail = nullptr;
}

// destructor
template <typename T>
SpaceRoute<T>::~SpaceRoute() {
    while (head != nullptr) {
        Node<T>* current = head;
        head = head->next;
        delete current;
    }
    tail = nullptr;
}

template<typename T>
void SpaceRoute<T>::addWaypointAtBeginning(T &data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        // if list is empty, creates a head and tail node
        head = newNode;
        tail = newNode;
    } else {
        //if list is not empty, creates a node before the head
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template<typename T>
void SpaceRoute<T>::addWaypointAtEnd(T &data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        // if list is empty, creates a head and tail node
        head = newNode;
        tail = newNode;
    } else {
        // if list is not empty, creates a node after the tail
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template<typename T>
void SpaceRoute<T>::addWaypointAtIndex(int index, T &data) {
    if (index == 0) {
        // checks if index is at zero, if so, uses previously defined method and ends
        addWaypointAtBeginning(data);
        return;
    } else if (index < 0) {
        // if index is invalid, nothing will happen
        return;
    }


    Node<T>* current = head;
    int count = 0;
    // finds the index position in the queue
    while (current && count < index) {
        current = current->next;
        count++;
    }
    if (!current) {
        // if the index goes beyond the list size, adds waypoint at end
        addWaypointAtEnd(data);
        return;
    }
    Node<T>* newNode = new Node<T>(data);
    newNode->next = current;
    newNode->prev = current->prev;

    // checks if there's a node before the selected node, if so, makes previous node the new node
    // if not, it means current is the head node, and replaces the current head with newNode
    if (current->prev) {
        current->prev->next = newNode;
    } else {
        head = newNode;
    }
    current->prev = newNode;
}

template<typename T>
void SpaceRoute<T>::removeWaypointAtBeginning() {
    if (!head) {
        // if list is empty, nothing happens
        return;
    }
    Node<T>* temp = head;
    if (head==tail) {
        // if one node in the list
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    // while temp is not used, it acts as temporary memory management
}

template<typename T>
void SpaceRoute<T>::removeWaypointAtEnd() {
    if (!tail) {
        // if list is empty
        return;
    }
    Node<T>* temp = tail;
    if (head == tail) {
        // if there's one node in list
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    // while temp is not used, it acts as temporary memory management
}

template<typename T>
void SpaceRoute<T>::removeWaypointAtIndex(int index) {
    if (!head) {
        // if list is empty
        return;
    }
    if (index < 0) {
        // if list is invalid
        return;
    }
    if (index==0) {
        removeWaypointAtBeginning();
    }

    Node<T>* current = head;
    int count = 0;
    while (current && count < index) {
        // searches for node
        current = current->next;
        count++;
    }
    if (!current) {
        // if node cannot be found
        return;
    }
    if (current == tail) {
        // if current is the last node
        removeWaypointAtEnd();
    }

    // connects nodes before deleting
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}

template<typename T>
void SpaceRoute<T>::traverseForward() {
    Node<T>* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template<typename T>
void SpaceRoute<T>::traverseBackward() {
    Node<T>* current = tail;
    while (current) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

template<typename T>
Node<T> *SpaceRoute<T>::getWaypoint(int index) {
    if (!head) {
        // if list is empty
        return nullptr;
    }
    if (index < 0) {
        // if index is invalid
        return nullptr;
    }
    Node<T>* current = head;
    int count = 0;
    // finds node in index
    while (current && count < index) {
        current = current->next;
        count++;
    }
    // if out of bounds, will return a nullptr instead
    return current;
}

template<typename T>
void SpaceRoute<T>::setWaypoint(int index, T &data) {
    // creates new node using the previous method
    Node<T>* newNode = getWaypoint(index);
    // if newNode is valid, it will set the new node
    if (newNode) {
        newNode->data = data;
    }
}
