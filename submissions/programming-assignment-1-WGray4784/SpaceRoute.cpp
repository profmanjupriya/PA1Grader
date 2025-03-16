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
    SpaceRoute() { //Constructor
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~SpaceRoute() { //Destructor
        Node<T>* current = this->head;
        while (current->next != nullptr) {
            head = head->next;
            delete current;
            current = head;
        }
    }

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = head;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void addWaypointAtEnd(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) {
            tail = newNode;
            head = tail;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }
        if (index == 0) {
            addWaypointAtBeginning(data);
        }
        if (index == size-1) {
            addWaypointAtEnd(data);
        }
        else {
            Node<T>* newNode = new Node<T>(data);
            Node<T>* temp = getWaypoint(index-1);
            Node<T>* temp2 = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = temp2;
            temp2->prev = newNode;
            size++;
        }
    }
    void removeWaypointAtBeginning() {
        if (size == 0) {
            cout << "List is empty. No waypoints to remove." << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        size--;
        if (size == 0) {
            head = nullptr;
            tail = nullptr;
        }
    }
    void removeWaypointAtEnd() {
        if (size == 0) {
            cout << "List is empty. No waypoints to remove." << endl;
        }
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        delete temp;
        size--;
        if (size == 0) {
            head = nullptr;
            tail = nullptr;
        }
    }
    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }
        if (index == 0) {
            removeWaypointAtBeginning();
        }
        if (index == size-1) {
            removeWaypointAtEnd();
        }
        else {
            Node<T>* temp = getWaypoint(index-1);
            Node<T>* temp2 = getWaypoint(index);
            temp->next = getWaypoint(index+1);
            temp2->next->prev = temp;
            delete temp2;
            size--;
        }
    }
    void traverseForward() {
        print();
    }
    void traverseBackward() {
        Node<T>* current = tail;
        while (current) {
            current->print();
            current = current->prev;
        }
        cout << endl;
    }
    Node<T>* getWaypoint(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return nullptr;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }
    void setWaypoint(int index, T& data) {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }
        if (index == 0) {
            head->data = data;
        }
        if (index == size-1) {
            tail->data = data;
        }
        else {
            Node<T>* temp = getWaypoint(index);
            temp->data = data;
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

