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
    void print() { cout << data << " " << endl; }
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
        head = nullptr;
        tail = nullptr;
        length = 0;
    };  // Constructor

    ~SpaceRoute() {
        Node<T> *temp = head;
        while (temp) {
            head = head -> next;
            delete temp;
            temp = head;
        }
    }; // Destructor

    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node(data);
        if (!head) {
            head = newNode;
            tail = newNode;
            length++;
        }
        else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
            length++;
        }
    }

    void addWaypointAtEnd(T& data) {
        Node<T> *newNode = new Node(data);
        if (!head) {
            head = newNode;
            tail = newNode;
            length++;
        }
        else {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
            length++;
        }
    }

    void addWaypointAtIndex(int index, T& data) {
        if (index == 0)
            addWaypointAtBeginning(data);
        else if (index == length)
            addWaypointAtEnd(data);
        else if (index < 0 || index > length)
            cout << "\nInvalid Index: index #" << index << " is out of range!\n" << endl;
        else {
            Node<T> *newNode = new Node(data);
            Node<T> *temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp -> next;
            }
            newNode -> next = temp -> next;
            temp -> next -> prev = newNode;
            newNode -> prev = temp;
            temp -> next = newNode;
            length++;
        }
    }

    void removeWaypointAtBeginning() {
        Node<T> *temp = head;
        head = head -> next;
        head -> prev = nullptr;
        delete temp;
        length--;
    }

    void removeWaypointAtEnd() {
        Node<T> *temp = tail;
        tail = tail -> prev;
        tail -> next = nullptr;
        delete temp;
        length--;
    }

    void removeWaypointAtIndex(int index) {
        if (index == 0)
            removeWaypointAtBeginning();
        else if (index == length - 1)
            removeWaypointAtEnd();
        else if (index < 0 || index >=  length)
            cout << "\nInvalid Index: index #" << index << " is out of range!\n" << endl;
        else {
            Node<T> *temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp -> next;
            }
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            delete temp;
            length--;
        }
    }

    void traverseForward() {
        Node<T>* current = head;
        while (current) {
            current->print();
            current = current -> next;
        }
    }

    void traverseBackward() {
        Node<T>* current = tail;
        while (current) {
            current -> print();
            current = current -> prev;
        }
    }

    Node<T>* getWaypoint(int index) {
        if (index == 0)
            return head;
        else if (index == length - 1)
            return tail;
        else if (index < 0 || index >= length) {
            cout << "\nInvalid Index: index #" << index << " is out of range!\n" << endl;
            return nullptr;
        }
        else {
            Node<T> *temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp -> next;
            }
            return temp;
        }
    }

    void setWaypoint(int index, T& data) {
        if (index == 0)
            head -> data = data;
        else if (index == length - 1)
            tail -> data = data;
        else if (index < 0 || index >= length) {
            cout << "\nInvalid Index: index #" << index << " is out of range!\n" << endl;
        }
        else {
            Node<T> *temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp -> next;
            }
            temp -> data = data;
        }
    }

    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
        }

};

