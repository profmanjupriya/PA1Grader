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
    int size;

public:
    SpaceRoute(): head(nullptr), tail(nullptr), size(0){}  // Constructor

    ~SpaceRoute() {
        // Destructor
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current->next;
            delete current;
            current = temp;
        }
        head=nullptr;
        tail=nullptr;
        size=0;
    }

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void addWaypointAtEnd(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (index == 0) {
            addWaypointAtBeginning(data);
            return;
        }
        if (index ==size) {
            addWaypointAtEnd(data);
            return;
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        Node<T>* newNode = new Node<T>(data);
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }

    void removeWaypointAtBeginning() {
        if (head == nullptr) {
            cout << "Empty space" << endl;
            return;
        }
        Node<T>* current = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        size--;
    }
    void removeWaypointAtEnd() {
        if (head == nullptr) {
            cout << "Empty space" << endl;
            return;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        size--;
    }

    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds." << endl;
            return;
    }
        if (index == 0) {
            removeWaypointAtBeginning();
            return;
        }
        if (index == size-1) {
            removeWaypointAtEnd();
            return;
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
        }

    void traverseForward() {
        if (head == nullptr) {
            return;
        }
        Node<T>* current = head;
        int index = 0;
        while (current != nullptr) {
            cout << "Waypoint" << index << ": " << current->data << endl;
            current = current->next;
            index++;
        }
    }

    void traverseBackward() {
        if (head == nullptr) {
            return;
        }
        Node<T>* current = tail;
        int index = size -1;
        while (current != nullptr) {
            cout << "Waypoint" << index << ": " << current->data << endl;
            current = current->prev;
            index--;
        }
    }

    Node<T>* getWaypoint(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds." << endl;
            return nullptr;
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    void setWaypoint(int index, T& data) {
        Node<T>* node = getWaypoint(index);
        if (node != nullptr) {
            node->data = data;
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

