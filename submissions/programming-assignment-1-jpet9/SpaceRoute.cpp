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
    SpaceRoute() : head(nullptr), tail(nullptr), size(0) {}       // Constructor, Initializes the default state of SpaceRoute

    ~SpaceRoute() {
        // Destructor, to ensure proper deletion and allocation of memory
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {    //creates newNode as the head and tail
            head = tail = newNode;
        } else {        //adds the data as the head
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void addWaypointAtEnd(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (!tail) {        //creates newNode as the head and tail
            head = tail = newNode;
        }else {             //adds data as tail
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    void addWaypointAtIndex(int index, T& data) {
        if (!head) {       //checks if there are elements
            return;
        }
        if (index <0) {     //checks bounds
            cout << "Index out of bounds!" << endl;
            return;
        }
        if (index == 0) {   //checks if index at 0, utilizes addWaypointAtBeginning()
            addWaypointAtBeginning(data);
            return;
        }
        Node<T>* current = head;
        int count = 0;
        while (current && count < index-1){         //finds element before index
            current = current->next;
            count++;
        }
        if (!current){
            addWaypointAtEnd(data);
        }else {         //adds new element to index
            Node<T>* newNode = new Node<T>(data);
            newNode->next = current->next;
            newNode->prev = current;

            if (current->next) {
                current->next->prev = newNode;
            }else {
                tail = newNode;
            }
            current->next = newNode;
        }
        size++;
    }
    void removeWaypointAtBeginning() {
        if (!head) {
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head) {     //head's prev is set to null
            head->prev = nullptr;
        }else {     //no head so tail is set to null
            tail = nullptr;
        }
        delete temp;
        size--;
    }
    void removeWaypointAtEnd() {
        if (!tail) {
            return;
        }
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }else {
            head = nullptr;
        }
        delete temp;
        size--;
    }
    void removeWaypointAtIndex(int index) {
        if (!head) {
            return;
        }
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            return;
        }
        if (index == 0) {
            removeWaypointAtBeginning();
            return;
        }
        if (index == size - 1) {
            removeWaypointAtEnd();
            return;
        }
        Node<T>* current = head;
        int count = 0;
        while (current && count < index){
            current = current->next;
            count++;
        }
        if (!current) {
            return;
        }
        if (current->next) {        //assigns currents next's previous to currents previous Node. Skips a Node
            current->next->prev = current->prev;
        }
        if (current->prev) {       //assigns currents previous next to currents next. Skips a Node
            current->prev->next = current->next;
        }
        delete current;
        size--;
    }
    void traverseForward() {
        Node<T>* current = head;
        while (current) {       //traverses until end
            current->print();
            current = current->next;
        }
        cout << endl;
    }
    void traverseBackward() {
        Node<T>* current = tail;
        while (current) {       //traverses until gets to head
            current->print();
            current = current->prev;
        }
        cout << endl;
    }
    Node<T>* getWaypoint(int index) {       //return waypoint from given index
        if (index <0 || index >= size) {
            return nullptr;
        }
        Node<T>* current = head;
        int count = 0;
        while (current && count <index) {
            current = current->next;
            count++;
        }
        return current;
    }
    void setWaypoint(int index, T& data) {      //sets waypoint with given data at given index
        if (index <0 || index >= size) {
            return;
        }
        Node<T>* newCurr = getWaypoint(index);
        if (newCurr) {
            newCurr->data = data;
        }
            cout << endl;
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

