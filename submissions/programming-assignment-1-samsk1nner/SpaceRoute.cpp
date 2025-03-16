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
    int length; // add

public:
    SpaceRoute() : head(nullptr), tail(nullptr), length(0) {}  // Constructor
    ~SpaceRoute() {
        if (head == nullptr) {
            cout << "There are no waypoints in your journey." << endl;
            return;
        }
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    } // Destructor with edge case handling

    void addWaypointAtBeginning(T& data) { // O(1) runtime; head created, new node is set to next, distance inc by 1
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head -> prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
        length++;
        cout << "Waypoint added at " << data << ", marking the beginning of the mission." << endl;
    }

    void addWaypointAtEnd(T& data) { // new node at tail with pointer to prev and head (make circular)
        Node<T>* newNode = new Node<T>(data);
        newNode->next = nullptr;
        if (tail != nullptr) {
            newNode->prev = tail;
            tail -> next = newNode;
            tail = newNode;
        } else {
            head = newNode;
            tail = newNode;
        }
        length++;
        cout << "Adding waypoint at " << data << ", Voyager 210's current planet."<< endl;
    }

    void addWaypointAtIndex(int index, T& data) { // insertion method for specific index
        if (index < 0 || index > length) {
            return;
        }
        if (index == 0) {
            addWaypointAtBeginning(data);
            cout << "Mission has kicked off. We have begun at " << data << endl; // possible change: does data represent the planet (node)?
            return;
        }
        if (index == length) {
            addWaypointAtEnd(data);
            cout << "We have landed on " << data << ", the furthest planet in celestial waypoint in the mission's journey." << endl; // same question as above.
            return;
        }
        Node<T>* newNode = new Node<T>(data);
        Node<T>* current = head;
        for (int i = 0; i < index -1; i++) {
            current = current->next;
        }
        newNode-> next = current->next;
        newNode-> prev = current;
        current-> next-> prev = newNode;
        current ->next = newNode;
        cout << "Waypoint has been inserted into the journey at " << data << endl;
        length++;
    }

    void removeWaypointAtBeginning() { // remove head, make sure tail pointer allows for circular LL
        if (head == nullptr) {
            cout << "The journey has not begun." << endl;
            return;
        }
        Node<T>* temp = head;
        head = head -> next;
        if (head != nullptr) {
            head -> prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
        length--;
    }

    void removeWaypointAtEnd() { // fix length decrease of list
        if (tail == nullptr) {
            cout << "There are no waypoints in the mission's journey." << endl;
            return;
        }
        Node<T>* temp = tail;
        tail = tail -> prev;
        if (tail != nullptr) {
            tail -> next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        // cout << "Removing waypoint at " << temp-> data << endl;
        length--;
    }

    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= length) {
            return;
        }
        if (index == 0) {
            removeWaypointAtBeginning();
            return;
        }
        if (index == length - 1) {
            removeWaypointAtEnd();
            return;
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) { // O(n) runtime
            current = current->next;
        }
        current -> prev -> next = current->next;
        current -> next -> prev = current->prev;
        cout << "Removing waypoint at " << current-> data << endl;
        delete current;
        length--;
    }

    void traverseForward() {
        if (head == nullptr) { // edge case if list is empty
            cout << "There are no waypoints. " << endl;
            return;
        }
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current -> data << " ";
            current = current -> next;
        }
    }

    void traverseBackward() {
        if (head == nullptr) {
            cout << "There are no waypoints. " << endl;
            return;
        }
        Node<T>* current = tail;
        while (current != nullptr) {
            cout << current -> data << " ";
            current = current -> prev;
        }
        cout << endl;
    }

    Node<T>* getWaypoint(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current -> next;
        }
        return current;
    }

    void setWaypoint(int index, T& data) { // needs work
        Node<T>* current = getWaypoint(index);
        if (current != nullptr) {
            current->data = data;
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