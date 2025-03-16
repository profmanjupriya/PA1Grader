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
    SpaceRoute() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    };  // Constructor
    ~SpaceRoute() {
        Node<T> *temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
            size--;
        }
    }; // Destructor

    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node<T>(data);
        if (size == 0) {
            newNode->next = head;
            head = newNode;
            tail = newNode;
            size++;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            size++;
        }

    };
    void addWaypointAtEnd(T& data) {
        Node<T> *newNode = new Node<T>(data);
        if (size == 0) {
            newNode->next = head;
            head = newNode;
            tail = newNode;
            size++;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    };
    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index > size-1) {
            cout<<"Index out of bounds"<<endl;
        }
        else if (index == 0) {
            addWaypointAtBeginning(data);
        }
        else if (index == size - 1) {
            addWaypointAtEnd(data);
        }
        else {
            Node<T> *newNode = new Node<T>(data);
            Node<T> *temp = head;
            for (int i = 0; i < index-1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            size++;
        }
    };
    void removeWaypointAtBeginning() {
        if (size == 0) {
            cout << "The list is empty" << endl;
        }
        else if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
        }
        else {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            head->prev = nullptr;
            size--;
        }
    };
    void removeWaypointAtEnd() {
        if (size == 0) {
            cout << "The list is empty" << endl;
        }
        else if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
        }
        else {
            Node<T> *temp = tail;
            tail = tail->prev;
            delete temp;
            tail->next = nullptr;
            size--;
        }
    };
    void removeWaypointAtIndex(int index) {
        if (index < 0 || index > size - 1) {
            cout << "Index out of bounds"<<endl;
        }
        else if (index == 0) {
            removeWaypointAtBeginning();
        }
        else if (index == size - 1) {
            removeWaypointAtEnd();
        }
        else {
            Node<T> *temp = head;
            for (int i = 0; i < index-1; i++) {
                temp = temp->next;
            }
            Node<T> *newNode = temp->next;
            temp->next = newNode->next;
            newNode->next->prev = temp;
            delete newNode;
            size--;
        }
    };
    void traverseForward() {
        if (size == 0) {
            cout << "The list is empty" << endl;
        }
        else {
            Node<T> *temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    };
    void traverseBackward() {
        if (size == 0) {
            cout << "The list is empty" << endl;
        }
        else {
            Node<T> *temp = tail;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->prev;
            }
        }
    };
    Node<T>* getWaypoint(int index) {
        if (index < 0 || index > size - 1) {
            cout << "Index out of bounds" << endl;
        }
        else {
            Node<T> *temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
    };
    void setWaypoint(int index, T& data) {
        if (index < 0 || index > size - 1) {
            cout << "Index out of bounds" << endl;
        }
        else {
            Node<T> *temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->data = data;
        }
    };
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

