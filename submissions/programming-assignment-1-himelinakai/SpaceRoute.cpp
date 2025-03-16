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
    SpaceRoute()  // Constructor
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~SpaceRoute() // Destructor
    {
        Node<T> *current = this->head;
        while (head) {
            head = head->next;
            delete current;
            current = head;
        }
    }

    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node<T>(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addWaypointAtEnd(T& data) {
        Node<T> *newNode = new Node<T>(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addWaypointAtIndex(int index, T& data) {
        if (index < 0) {
            cout << "Invalid index." << endl;
            return;
        }

        if (index == 0) {
            return addWaypointAtBeginning(data);
        }

        Node<T> *current = getWaypoint(index);
        Node<T> *newNode = new Node<T>(data);

        if (current == tail) {
            return addWaypointAtEnd(data);
        }

        if (current != nullptr) {
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }

    void removeWaypointAtBeginning() {
        if (head == nullptr) {
            cout << "Journey has not started. No waypoints yet." << endl;
            return;
        }

        Node<T> *current = head;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete current;
    }

    void removeWaypointAtEnd() {
        if (head == nullptr) {
            cout << "Journey has not started. No waypoints yet." << endl;
            return;
        }

        Node<T> *current = tail;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete current;
    }

    void removeWaypointAtIndex(int index) {
        if (head == nullptr) {
            cout << "Journey has not started. No waypoints yet." << endl;
            return;
        }

        if (index < 0) {
            cout << "Invalid index." << endl;
            return;
        }

        if (index == 0) {
            return removeWaypointAtBeginning();
        }

        Node<T> *current = getWaypoint(index);

        if (current == tail) {
            return removeWaypointAtEnd();
        }

        if (current != nullptr) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    void traverseForward() {
        if (head == nullptr) {
            cout << "Journey has not started. No waypoints yet." << endl;
            return;
        }

        Node<T> *current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    void traverseBackward() {
        if (head == nullptr) {
            cout << "Journey has not started. No waypoints yet." << endl;
            return;
        }

        Node<T> *current = tail;
        while (current != nullptr) {
            cout << current->data << " <- ";
            current = current->prev;
        }
        cout << endl;
    }

    Node<T>* getWaypoint(int index) {
        if (head == nullptr) {
            cout << "Journey has not started. No waypoints yet." << endl;
            return nullptr;
        }

        if (index < 0) {
            cout << "Invalid index." << endl;
            return nullptr;
        }

        if (index == 0) {
            return head;
        }

        Node<T> *current = head;

        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Invalid index." << endl;
            return nullptr;
        }

        if (current == tail) {
            return tail;
        }

        return current;
    }

    void setWaypoint(int index, T& data) {
        if (head == nullptr) {
            cout << "Journey has not started. No waypoints yet." << endl;
            return;
        }

        Node<T> *current = getWaypoint(index);
        if (current != nullptr) {
            current->data = data;
            return;
        }
    }


    void print(){
        if (head == nullptr) {
            cout << "Journey has not started. No waypoints yet." << endl;
            return;
        }

        Node<T> *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

