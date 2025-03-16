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
    SpaceRoute() : head(nullptr), tail(nullptr){}

    ~SpaceRoute() {
        Node<T>* current = head;
        while (current) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }


    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }
    void addWaypointAtEnd(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void addWaypointAtIndex(int index, T& data) {
        if (index == 0) {
            addWaypointAtBeginning(data);
            return;
        }
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr && count < index - 1) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            addWaypointAtEnd(data);
        }else {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;

            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
    }
    void removeWaypointAtBeginning() {
        if ( head == nullptr) {
            cout << "No waypoint to remove." << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }else {
            tail = nullptr;
        }

        delete temp;

    }

    void removeWaypointAtEnd() {
        if (head == nullptr) {
            cout << "No waypoint to remove." << endl;
            return;
        }
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }else {
            head = nullptr;
        }
        delete temp;
    }

    void removeWaypointAtIndex(int index) {
        if (head == nullptr) {
            cout<< "No waypoint to remove." << endl;
            return;
        }
        if (index == 0) {
            removeWaypointAtBeginning();
            return;
        }
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr && count < index) {
            current = current->next;
            count++;
        }
        if ( current == nullptr) {
            cout << "No waypoint to remove" << endl;
            return;
        }
        if (current == tail) {
            removeWaypointAtEnd();
            return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    void traverseForward() {
        if (head == nullptr) {
            cout << "No waypoint to print." << endl;
            return;
        }
        Node<T>* current = head;
        cout << "Waypoints from first to last: " << endl;
        while (current != nullptr) {
            cout << current->data << " - ";
            current = current->next;
        }
    }
    void traverseBackward() {
        if (tail == nullptr) {
            cout << "No waypoint to print." << endl;
            return;
        }
        Node<T>* current = tail;
        cout << "Waypoints from last to first: " << endl;
        while (current != nullptr) {
            cout << current->data << " - ";
            current = current->prev;
        }

    }
    Node<T>* getWaypoint(int index) {
        if ( head == nullptr) {
            cout << "No waypoints in list." << endl;
            return nullptr;;
        }
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr && count < index) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            cout << "Index is out of range." << endl;
            return nullptr;
        }
        return current;
    }

    void setWaypoint(int index, T& data) {
        Node<T>* waypoint = getWaypoint(index);
        if (waypoint != nullptr) {
            waypoint->data = data;
            cout << "Waypoint at index " << index << "changed to " << waypoint->data << endl;;
        }
    }
    void print() {
        if (head == nullptr) {
            cout << "No waypoints to print." << endl;
            return;
        }
        Node<T>* current = head;
        cout << "Space route: " << endl;
        while (current) {
            current->print();
            current = current->next;
        }
        cout << endl;
        }

    };





