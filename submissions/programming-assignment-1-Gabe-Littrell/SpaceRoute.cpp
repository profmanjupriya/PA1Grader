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
    SpaceRoute() { // Constructor
        head = NULL;
        tail = NULL;
        length = 0;
    }
    ~SpaceRoute() { // Destructor
        Node<T> *current = this->head;
        while (head) {
            head = head->next;
            delete current;
            current = head;
        }
    }

    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node<T>(data);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        length++;
    }
    void addWaypointAtEnd(T& data) {
        if (length == 0) {
            addWaypointAtBeginning(data);
            return;
        }

        Node<T> *newNode = new Node<T>(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;

        length++;
    }
    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index > length) {
            cout << "Invalid waypoint index." << endl;
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

        Node<T>* newNode = new Node<T>(data);
        Node<T>* tempNode = getWaypoint(index - 1);
        newNode->prev = tempNode;
        newNode->next = tempNode->next;
        tempNode->next = newNode;
        newNode->next->prev = newNode;
        length++;

    }
    void removeWaypointAtBeginning() {
        if (length == 0) {
            cout << "Can't delete from an empty mission log." << endl;
            return;
        }

        Node<T>* tempNode = head;
        head = head-> next;
        head->prev = nullptr;
        delete tempNode;
        length--;
    }
    void removeWaypointAtEnd() {
        if (length == 0) {
            cout << "Can't delete from an empty mission log." << endl;
            return;
        }

        Node<T>* tempNode = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete tempNode;
        length--;
    }
    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= length) {
            cout << "Invalid waypoint index for deletion." << endl;
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

        Node<T>* tempNode = getWaypoint(index);
        tempNode->next->prev = tempNode->prev;
        tempNode->prev->next = tempNode->next;
        delete tempNode;
        length--;
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
        if (index < 0 || index >= length) {
            return nullptr;
        }

        if (index == length - 1) {
            return tail;
        }

        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }
    void setWaypoint(int index, T& data) {
        if (index < 0 || index >= length) {
            cout << "Unable to set waypoint at this index." << endl;
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        Node<T>* tempNode = getWaypoint(index);

        if (index == 0) {
            newNode->next = head->next;
            newNode->next->prev = newNode;
            head = newNode;
            delete tempNode;
            return;
        }

        if (index == length - 1) {
            newNode->prev = tail->prev;
            newNode->prev->next = newNode;
            tail = newNode;
            delete tempNode;
            return;
        }

        newNode->prev = tempNode->prev;
        newNode->next = tempNode->next;
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
        delete tempNode;
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

