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
    SpaceRoute() { // Constructor
        head = nullptr;
        tail = nullptr;
    }
    ~SpaceRoute() { // Destructor
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addWaypointAtEnd(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail ==nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addWaypointAtIndex(int index, T& data) {
         Node<T>* current = head;
        for (int i = 0; i < index - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            addWaypointAtEnd(data);
        }
        else {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            else {
                tail = newNode;
            }
        current->next = newNode;
        }
    }

    void removeWaypointAtBeginning() {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
    }

    void removeWaypointAtEnd() {
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head= nullptr;
        }
    }

    void removeWaypointAtIndex(int index) {
        Node<T>* current = head;

        for (int i = 1; i < index && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) return;

        if (current == tail) {
            removeWaypointAtEnd();
            return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }


    void traverseForward() {
        Node<T>* current = head;
        while (current != nullptr) {
            current->print();
            current = current->next;
        }
    }
    void traverseBackward() {
        Node<T>* current = tail;
        while (current != nullptr) {
            current->print();
            current = current->prev;
        }
    }

    Node<T>* getWaypoint(int index) {
        if (index < 0 ) return nullptr;
        Node<T>* current = head;
        for (int i = 1; i < index && current != nullptr; i++) {
            current = current->next;
        }
        return current;
    }

    void setWaypoint(int index, T& data) {
        Node<T>* newNode = getWaypoint(index);
        if (newNode != nullptr) {
            newNode->data = data;
        }
    }
    void print(){
        Node<T>* current = head;
        while (current) {
            current->print();
            current = current->next;
        }
        cout << endl;
    }
};
