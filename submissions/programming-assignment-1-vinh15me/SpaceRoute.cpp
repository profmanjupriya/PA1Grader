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
    int sizeOfTheVeryCoolSpaceRoute = 0;

public:
    SpaceRoute() {
        head = nullptr;
        tail = nullptr;
        sizeOfTheVeryCoolSpaceRoute = 0;
    }
    ;  // Constructor
    ~SpaceRoute() {
        Node<T>* temp = head;
        while (head != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }; // Destructor

    void addWaypointAtBeginning(T& data) {
        if (sizeOfTheVeryCoolSpaceRoute == 0) {
            head = new Node<T>(data);
            head->prev = nullptr;
            head->next = nullptr;
            tail = head;
        }
        else {
            Node<T>* temp = new Node<T>(data);
            temp->prev = nullptr;
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        sizeOfTheVeryCoolSpaceRoute++;
    }

    void addWaypointAtEnd(T& data) {
        if (sizeOfTheVeryCoolSpaceRoute == 0) {
            head = new Node<T>(data);
            head->prev = nullptr;
            head->next = nullptr;
            tail = head;
        }
        else {
            Node<T>* temp = new Node<T>(data);
            temp->prev = tail;
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
        }
        sizeOfTheVeryCoolSpaceRoute++;
    }

    void addWaypointAtIndex(int index, T& data) {
        if (sizeOfTheVeryCoolSpaceRoute == 0 || index == 0) {
            addWaypointAtBeginning(data);
        }
        else if (sizeOfTheVeryCoolSpaceRoute == index) {
            addWaypointAtEnd(data);
        }
        else if (index > sizeOfTheVeryCoolSpaceRoute - 1 || index < 0) {
            cout << "Index out of bounds" << endl;
        }
        else {
            Node<T>* temp = head;
            for (int i = 1; i < index; ++i) {
                temp = temp->next;
            }
            Node<T>* newNode = new Node<T>(data);
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
            temp->prev = newNode;
            sizeOfTheVeryCoolSpaceRoute++;
        }
    }

    void removeWaypointAtBeginning() {
        if (sizeOfTheVeryCoolSpaceRoute == 0) {
            cout << "The list is empty" << endl;
        }
        else if (sizeOfTheVeryCoolSpaceRoute == 1) {
            Node<T>* temp = head;
            head = nullptr;
            tail = nullptr;
            sizeOfTheVeryCoolSpaceRoute--;
            delete temp;
        }
        else {
            Node<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            sizeOfTheVeryCoolSpaceRoute--;
        }
    }
    void removeWaypointAtEnd() {
        if (sizeOfTheVeryCoolSpaceRoute == 0) {
            cout << "The list is empty" << endl;
        }
        else if (sizeOfTheVeryCoolSpaceRoute == 1) {
            Node<T>* temp = head;
            head = nullptr;
            tail = nullptr;
            sizeOfTheVeryCoolSpaceRoute--;
            delete temp;
        }
        else {
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            sizeOfTheVeryCoolSpaceRoute--;
        }
    }
    void removeWaypointAtIndex(int index) {
        if (sizeOfTheVeryCoolSpaceRoute == 0) {
            cout << "The list is empty" << endl;
        }
        else if (sizeOfTheVeryCoolSpaceRoute - 1 < index || index < 0) {
            cout << "Index out of bounds" << endl;
        }
        else if (index == 0) {
            removeWaypointAtBeginning();
        }
        else if (index == sizeOfTheVeryCoolSpaceRoute - 1) {
            removeWaypointAtEnd();
        }
        else {
            Node<T>* temp = head;
            for (int i = 0; i < index; ++i) {
                temp = temp->next; // [0,1,2,3,4,5,6] remove 4
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            sizeOfTheVeryCoolSpaceRoute--;
        }
    }
    void traverseForward() {
        Node<T> * temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void traverseBackward() {
        Node<T>* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }
    Node<T>* getWaypoint(int index) {
        if (index < 0 || index > sizeOfTheVeryCoolSpaceRoute - 1) {
            cout << "Index out of bounds" << endl;
        }
        else if (sizeOfTheVeryCoolSpaceRoute == 0) {
            cout << "The list is empty" << endl;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }
    void setWaypoint(int index, T& _data) {
        if (index < 0 || index > sizeOfTheVeryCoolSpaceRoute - 1) {
            cout << "Index out of bounds" << endl;
        }
        else if (sizeOfTheVeryCoolSpaceRoute == 0) {
            cout << "The list is empty" << endl;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = _data;
    }
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl << "Size: " << sizeOfTheVeryCoolSpaceRoute << endl;
        }

};

