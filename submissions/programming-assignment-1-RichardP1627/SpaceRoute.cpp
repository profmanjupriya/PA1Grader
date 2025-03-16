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

/* READ ME
 * addWaypointAtBeginning: Creates a new waypoint at the beginning of the list ; O(1) since execution time of this method remains constant.
 * addWaypointAtEnd: Creates a new waypoint at the end of the list ; O(1) since execution time of this method remains constant.
 * addWaypointAtIndex: Creates a new waypoint at a specified index of the list ; O(n) since the method implements a for loop that increments until the index to add a waypoint at the specified index.
 * removeWaypointAtBeginning: Removes the first waypoint in the list; O(1) since executions time of the method remains constant.
 * removeWaypointAtEnd: Removes the last waypoint in the list ; O(1) since execution time of the method remains constant.
 * removeWaypointAtIndex: Removes the waypoint at the specified index ; O(n) since the method implements a for loop that increments until the index to remove the specified waypoint.
 * traverseForward: Prints all the waypoints in the list from front the back ; O(n) since there is a while loop that goes through every index of the list.
 * traverseBackward: Prints all the waypoint in the list from back to front ; O(n) since there is a while loop that goes through every index of the list.
 * getWaypoint: Returns the waypoint at a specified index ; O(n) since there is a for loop that executes through half of the list depending on which half the index falls in.
 * setWaypoint: Changes the data of a waypoint at a specified index ; O(n) since there is a for loop that executes through half of the list depending on which half the index falls in.
 * print: Prints out the entire list ; O(n) since it iterates through each index of the list to print.
*/

template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;

public:
    SpaceRoute() {    // Constructor
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    ~SpaceRoute() {   // Destructor
        Node<T> *temp = head;
        while (head) {
            head = head -> next;
            delete temp;
            temp = head;
        }
    }
    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node<T> (data);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
        length++;
    }
    void addWaypointAtEnd(T& data) {
        Node<T> *newNode = new Node<T> (data);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        length++;
    }
    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index > length) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (index == 0) {
            addWaypointAtBeginning(data);
            return;
        }
        if (index == length) {
            addWaypointAtEnd(data);
            return;
        }
        Node<T> *newNode = new Node<T> (data);
        Node<T> *curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr -> next;
        }
        Node<T> *temp = curr -> next;
        newNode -> prev = curr;
        newNode -> next = temp;
        curr -> next = newNode;
        temp -> prev = newNode;
        length++;
    }
    void removeWaypointAtBeginning() {
        if (length == 0) {
            cout << "No Waypoint at Beginning" << endl;
            return;
        }
        Node<T> *temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head -> next;
            head -> prev = nullptr;
        }
        delete temp;
        length--;
    }
    void removeWaypointAtEnd() {
        if (length == 0) {
            cout << "No Waypoint at End" << endl;
            return;
        }
        Node<T> *temp = tail;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail -> prev;
            tail -> next = nullptr;
        }
        delete temp;
        length--;
    }
    void removeWaypointAtIndex(int index) {
        if (index < 0 || index > length) {
            cout << "Index out of bounds" << endl;
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
        Node<T> *curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr -> next;
        }
        curr -> next -> prev = curr -> prev;
        curr -> prev -> next = curr -> next;
        delete curr;
        length--;
    }
    void traverseForward() {
        if (length == 0) {
            cout << "No Waypoints to Traverse" << endl;
            return;
        }
        Node<T> *curr = head;
        while (curr != nullptr) {
            cout << curr -> data;
            curr = curr -> next;
            if (curr != nullptr) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    void traverseBackward() {
        if (length == 0) {
            cout << "No Waypoints to Traverse" << endl;
            return;
        }
        Node<T> *curr = tail;
        while (curr != nullptr) {
            cout << curr -> data;
            curr = curr -> prev;
            if (curr != nullptr) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    Node<T>* getWaypoint(int index) {
        if (index < 0 || index > length) {
            cout << "Index out of bounds" << endl;
            return nullptr;
        }
        if (length == 0) {
            cout << "No Waypoints Set" << endl;
            return nullptr;
        }
        if (index > length / 2) {
            Node<T> *curr = tail;
            for (int i = length - 1; i > index; i--) {
                curr = curr -> prev;
            }
            return curr;
        }
        else {
            Node<T> *curr = head;
            for (int i = 0; i < index; i++) {
                curr = curr -> next;
            }
            return curr;
        }
    }
    void setWaypoint(int index, T& data) {
        if (index < 0 || index > length) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (index == 0) {
            head -> data = data;
            return;
        }
        if (index == length - 1) {
            tail -> data = data;
            return;
        }
        if (index > length / 2) {
            Node<T> *curr = tail;
            for (int i = length - 1; i > index; i--) {
                curr = curr -> prev;
            }
            curr -> data = data;
        }
        else {
            Node<T> *curr = head;
            for (int i = 0; i < index; i++) {
                curr = curr -> next;
            }
            curr -> data = data;
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

