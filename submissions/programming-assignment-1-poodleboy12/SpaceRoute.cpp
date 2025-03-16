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
    SpaceRoute() {
        head = nullptr;
        tail = nullptr;
    }  // Constructor
    ~SpaceRoute() {

    } // Destructor

    void addWaypointAtBeginning(T& data) { // O(1) because we're only doing 1 condition to see whether head and tail are null.
        Node<T>* newNode = new Node<T>(data);
        Node<T>* temp = head;
        if (head == nullptr && tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = temp;
            temp->prev = newNode;
            head = newNode;
        }
    }
    void addWaypointAtEnd(T& data) { // O(1) because we're only doing 1 condition to see whether head and tail are null.
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr && tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void addWaypointAtIndex(int index, T& data) { // O(n) because the loop will go a maximum of n times and the operations are O(1).
        int currIndex = 0;
        Node<T> *newNode = new Node<T>(data);
        Node<T> *temp = head;
        if (index < 0) {
            cout << "Error, no indexes are less than 0." << endl;
        }
        else if (index == 0) {
            addWaypointAtBeginning(data);
        }
        else {
            for (currIndex = 0; (currIndex < index && temp != nullptr); ++currIndex) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                if (currIndex == index) {
                    addWaypointAtEnd(data);
                }
                else {
                    cout << "Error , no indexes greater than index" << endl;
                }
            }
            else {
                temp->prev->next = newNode;
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev = newNode;
            }
        }
    }
    void removeWaypointAtBeginning() { // O(1) because we're just doing one condition to see  whether head is null or not.
        if (head == nullptr) {
            cout << "Cant remove an empty list." << endl;
        }
        else {
            Node<T> *temp = head;
            temp->next->prev = nullptr;
            head = temp->next;
            temp = nullptr;
         }
    }
    void removeWaypointAtEnd() { // O(1) because we're just doing one condition to see  whether head is null or not.
        if (head == nullptr) {
            cout << "Can't remove an empty list." << endl;
        }
        else {
            Node<T> *temp = tail;
            tail = temp->prev;
            tail->prev = temp->prev->prev;
            tail->next = nullptr;
            temp = nullptr;
        }
    }
    void removeWaypointAtIndex(int index) { // O(n) because the loop will go a maximum of n times and the operations are O(1).
        Node<T> * temp = head;
        int currIndex = 0;
        if (index < 0) {
            cout << "Error can't remove index below 0." << endl;
        }
        else {
            for (currIndex = 0; (currIndex < index) && (temp != nullptr); ++currIndex) {
                 temp = temp->next;
            }
            if (temp != nullptr) {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
            }
            else {
                cout << "Error can't remove a null pointer" << endl;
            }
        }
    }
    void traverseForward() { // O(n) because the loop will go a maximum of n times and the operations are O(1).
         Node<T> *temp = head;
         while (temp != nullptr) {
             temp->print();
             temp = temp->next;
         }
    }
    void traverseBackward() { // O(n) because the loop will go a maximum of n times and the operations are O(1).
         Node<T> *temp = tail;
         while (temp != nullptr) {
             temp->print();
             temp = temp->prev;
         }
    }
    Node<T>* getWaypoint(int index) { // O(index) because the loop will go a maximum of n times and the operations are O(1).
        Node<T> *temp = head;
        int currIndex;
        if (index < 0) {
            return nullptr;
        }
        else {
            for (currIndex = 0; (currIndex < index) && (temp != nullptr); ++currIndex) {
                temp = temp->next;
            }
            return temp;
        }
    }
    void setWaypoint(int index, T& data) { // O(n) because the loop will go a maximum of n times and the operations are O(1).
        Node<T> *temp = getWaypoint(index);
        if (temp != nullptr) {
            temp->data = data;
        }
    }
    void print(){ //O(n) because the loop will go a maximum of n times and the operations are O(1).

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }




};

