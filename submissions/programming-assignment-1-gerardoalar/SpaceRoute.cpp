#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(NULL), prev(NULL) {}
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
        head = NULL;
        tail = NULL;
    }
    SpaceRoute(T value) {// Constructor
        this->head = new Node<T>(value);
        this->tail.prev = NULL;
    }
    ~SpaceRoute() { //destructor
        Node<T> *current = this->head;
        while (head != NULL) {
            head = head->next;
            delete current;
            current = head;
        }
    }

    void addWaypointAtBeginning(T& data) {
        if (head == NULL) {
            head = new Node<T>(data);
            tail = head;
        }
        Node<T>* newNode = new Node<T>(data);
        newNode->next = this->head;
        head->prev = newNode;
        head = newNode;
    }

    void addWaypointAtEnd(T& data) {
        if (head == NULL) {
            head = new Node<T>(data);
            tail = head;
        }
        else {
            Node<T>* newNode = new Node<T>(data);
            this->tail->next = newNode;
            tail = newNode;
        }
    }
    void addWaypointAtIndex(int index, T& data) {
        if (index == 0) {
            addWaypointAtBeginning(data);
        }
        else {
            Node<T>* temp = getWaypoint(index);
            Node<T>* current = getWaypoint(index - 1);
            Node<T>* newNode = new Node<T>(data);
            current->next = newNode;
            newNode->prev = current;
            newNode->next = temp;
            temp->prev = newNode;
        }
    }
    void removeWaypointAtBeginning() {
        if (head == NULL) {
        }
        else {
            Node<T> *temp = this->head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }
    void removeWaypointAtEnd() {
        Node<T> *temp = this->tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
    void removeWaypointAtIndex(int index) {
        if (index == 0) {
            removeWaypointAtBeginning();
        }
        Node<T> *temp = getWaypoint(index);
        Node<T> *current = temp->prev;
        current->next = temp->next;
        temp->next->prev = current;
        delete temp;
    }
    void traverseForward() {
        if (head == NULL) {
            cout << "No space route!" << endl;
            return;
        }
        Node<T> *current = this->head;
        cout << current->data << " ";
        while (current->next != NULL) {
            current = current->next;
            cout << current->data << " ";
        }
        cout << endl;
    }
    void traverseBackward() {
        if (tail == NULL) {
            cout << "No space route!" << endl;
            return;
        }
        Node<T> *current = this->tail;
        cout << current->data << " ";
        while (current->prev != NULL) {
            current = current->prev;
            cout << current->data << " ";
        }
        cout << endl;
    }
    Node<T>* getWaypoint(int index) {
        Node<T> *current = this->head;
        for (int i = 0; i < index; i++) {
            if (current->next != NULL) {
                current = current->next;
            }
            else {
                cout<<"No waypoint found at index "<<index<<endl;
                return NULL;
            }
        }
        return current;
    }
    void setWaypoint(int index, T& data) {
        Node<T> *current = this->getWaypoint(index);
        current->data = data;
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

