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
    void print()
    {
            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }
};

template <typename T>
SpaceRoute<T>::~SpaceRoute() {
    Node<T>* current = head;
    while (current) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
void SpaceRoute<T> :: addWaypointAtBeginning(T& data)
{
    Node<T>* newNode = new Node<T>(data);
    if (!tail)
    {
        head = tail = newNode;
    } else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <typename T>
void SpaceRoute<T>::addWaypointAtEnd(T& data)
{
    Node<T>* newNode = new Node<T>(data);
    if (!tail)
    {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <typename T>
void SpaceRoute<T>::addWaypointAtIndex(int index, T& data) {
    if (index < 0) return;

    if (index == 0) {
        addWaypointAtBeginning(data);
        return;
    }

    Node<T>* newNode = new Node<T>(data);
    Node<T>* current = head;
    int count = 0;

    while (current && count < index) {
        current = current->next;
        count++;
    }

    if (current) {
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev) current->prev->next = newNode;
        current->prev = newNode;
    } else {
        addWaypointAtEnd(data);  // If index is out of bounds, add at the end
    }
}

template <typename T>
void SpaceRoute<T>::removeWaypointAtBeginning() {
    if (!head) return;

    Node<T>* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;

    if (!head) tail = nullptr;  // If the list is empty now, tail should also be null
}

template <typename T>
void SpaceRoute<T>::removeWaypointAtEnd() {
    if (!tail) return;

    Node<T>* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    delete temp;

    if (!tail) head = nullptr;  // If the list is empty now, head should also be null
}

template <typename T>
void SpaceRoute<T>::removeWaypointAtIndex(int index) {
    if (index < 0 || !head) return;

    if (index == 0) {
        removeWaypointAtBeginning();
        return;
    }

    Node<T>* current = head;
    int count = 0;

    while (current && count < index) {
        current = current->next;
        count++;
    }

    if (current) {
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        delete current;
    }
}

template <typename T>
void SpaceRoute<T>::traverseForward() {
    Node<T>* current = head;
    while (current) {
        current->print();
        current = current->next;
    }
    cout << endl;
}

template <typename T>
void SpaceRoute<T>::traverseBackward() {
    Node<T>* current = tail;
    while (current) {
        current->print();
        current = current->prev;
    }
    cout << endl;
}

template <typename T>
Node<T>* SpaceRoute<T>::getWaypoint(int index) {
    if (index < 0) return nullptr;

    Node<T>* current = head;
    int count = 0;
    while (current && count < index) {
        current = current->next;
        count++;
    }

    return current;
}

template <typename T>
void SpaceRoute<T>::setWaypoint(int index, T& data) {
    Node<T>* node = getWaypoint(index);
    if (node) {
        node->data = data;
    }
}
