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
    int length;

public:
    SpaceRoute() {
        this->length = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }
    ~SpaceRoute() {
        Node<T>* curr = this->head;
        while (head) {
            head = head->next;
            delete curr;
            curr = head;
        }
    }

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
        length++;
    }
    void addWaypointAtEnd(T& data) {
        Node<T>* newNode = new Node<T>(data);

        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }
    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index >= length) {
            cout << "Index out of bounds" << endl;
        }
        if (index == 0) {
            addWaypointAtBeginning(data);
        }
        if (index == length) {
            addWaypointAtEnd(data);
        }

        Node<T>* newNode = new Node<T>(data);
        Node<T>* temp = getWaypoint(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }
    void removeWaypointAtBeginning() {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        length--;
    }
    void removeWaypointAtEnd() {
        Node<T>* temp = tail;
        tail = tail->prev;
        delete temp;
        length--;
    }
    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= length) {
            cout << "No such Waypoint at specified index." << endl;
        }
        if (index == 0) {
            removeWaypointAtBeginning();
        }
        if (index == length) {
            removeWaypointAtEnd();
        }

        Node<T>* delNode = getWaypoint(index);
        Node<T>* sucNode = getWaypoint(index - 1);
        Node<T>* nextNode = getWaypoint(index + 1);
        sucNode->next = delNode->next;
        nextNode->prev = delNode->prev;
        delete delNode;
        length--;
    }
    void traverseForward() {
        for (int i = 0; i < length; i++) {
            cout << "Waypoint " << i << ": " << getWaypoint(i)->data << endl;
        }
        cout << "All Waypoints successfully listed." << endl;
    }
    void traverseBackward() {
        for (int i = length - 1; i >= 0; i--) {
            cout << "Waypoint " << i << ": " << getWaypoint(i)->data << endl;
        }
        cout << "All Waypoints successfully listed." << endl;
    }
    Node<T>* getWaypoint(int index) {
        if (index < 0 || index >= length) {
            cout << "No such Waypoint exists." << endl;
            return nullptr;
        }

        Node<T> *temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp;
    }
    void setWaypoint(int index, T& data) {
        Node<T>* temp = getWaypoint(index);
        temp->data = data;
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

