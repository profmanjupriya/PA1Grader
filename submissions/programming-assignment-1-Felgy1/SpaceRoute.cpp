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
    int length;
    Node<T>* head;
    Node<T>* tail;

public:
    SpaceRoute() {
        length = 0;
        this->head = nullptr;
        this->tail = nullptr;
}  // Constructor
    ~SpaceRoute() {
        Node<T>* temp = this->head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }// Destructor


    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void addWaypointAtEnd(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (length == 0) {
            tail = newNode;
            head = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index >= length) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (index == 0) {
            addWaypointAtBeginning(data);
        }
        if (index == length - 1) {
            addWaypointAtEnd(data);
        } else {
            Node<T>* newNode = new Node<T>(data);
            Node<T>* temp = getWaypoint(index - 1);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            length++;
        }
    }

    void removeWaypointAtBeginning() {
        if (length == 0) {
            cout << "The route is empty" << endl;
            return;
        }
        Node<T>* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }
        delete temp,
        length--;
    }

    void removeWaypointAtEnd() {
        if (length == 0) {
            cout << "The route is empty" << endl;
            return;
        }
        Node<T>* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T>* pre = head;
            while (temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp,
        length--;
    }

    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (index == 0) {
            removeWaypointAtBeginning();
        }
        if (index == length - 1) {
            removeWaypointAtEnd();
        }

        Node<T>* prev = getWaypoint(index - 1);
        Node<T>* temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }

    void traverseForward() {
        if (length == 0) {
            cout << "The route is empty" << endl;
            return;
        }
        Node<T>* current = head;
        while (current) {
            current->print();
            current = current->next;
        }
        cout << endl;
    }

    void traverseBackward() {
        if (length == 0) {
            cout << "The route is empty" << endl;
            return;
        }
        Node<T>* current = tail;
        while (current) {
            current->print();
            current = current->prev;
        }
        cout << endl;
    }

    Node<T>* getWaypoint(int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of bounds" << endl;
            return nullptr;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void setWaypoint(int index, T& data) {
        Node<T>* temp = this->getWaypoint(index);
        if (temp) {
            temp->data = data;
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

