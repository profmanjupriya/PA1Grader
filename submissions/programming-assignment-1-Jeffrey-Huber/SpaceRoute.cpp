#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node {
public:
    T &data;
    Node *next;
    Node *prev;

    Node(T &d) : data(d), next(nullptr), prev(nullptr) {
    }

    void print() { cout << data << " "; }
};

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string &n, double d, const string &log);

    const string &getName() const;

    double getDistance() const;

    const string &getMissionLog() const;

    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};

template<typename T>
class SpaceRoute {
private:
    Node<T> *head;
    Node<T> *tail;
    int length;

public:
    SpaceRoute() {
        this->length = 0;
        T startingData = T();
        this->head = nullptr;
        this->tail = this->head;
    } // Constructor
    ~SpaceRoute() {
        Node<T> *temp = head;
        while (temp->next != nullptr) {
            Node<T> *remove = temp->next;
            delete temp;
            temp = remove;
        }
        delete temp;
    } // Destructor

    void addWaypointAtBeginning(T &data) {
        Node<T> *newNode = new Node<T>(data);
        if (length == 0) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        length++;
    }

    void addWaypointAtEnd(T &data) {
        Node<T> *newNode = new Node<T>(data);
        if (length == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void addWaypointAtIndex(int index, T &data) {
        if (index < 0 || index > length) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (index == 0) {
            addWaypointAtBeginning(data);
        } else if (index == length) {
            addWaypointAtEnd(data);
        } else {
            Node<T> *newNode = new Node<T>(data);
            Node<T> *temp = getWaypoint(index);
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            length++;
        }
    }


    void removeWaypointAtBeginning() {
        if (length == 0) {
            cout << "List empty!" << endl;
            return;
        }
        Node<T> *temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    void removeWaypointAtEnd() {
        if (length == 0) {
            cout << "List empty!" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            length--;
            return;
        }
        Node<T> *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        length--;
    }

    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (length == 0) {
            return;
        }
        if (index == 0) {
            removeWaypointAtBeginning();
        } else if (index == length - 1) {
            removeWaypointAtEnd();
        } else {
            Node<T> *temp = getWaypoint(index);
            Node<T> *next = temp->next;
            Node<T> *prev = temp->prev;
            prev->next = next;
            next->prev = prev;
            delete temp;
            length--;
        }
    }

    void traverseForward() {
        Node<T> *temp = head;
        for (int i = 0; i < length; i++) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void traverseBackward() {
        Node<T> *temp = tail;
        for (int i = 0; i < length; i++) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }

    Node<T> *getWaypoint(int index) {
        if (index < 0 || index >= length)
            return NULL;
        Node<T> *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void setWaypoint(int index, T &data) {
        if (index < 0 || index > length) {
            cout << "Index out of bounds" << endl;
            return;
        }
        removeWaypointAtIndex(index);
        addWaypointAtIndex(index, data);
    }

    void print() {
        if (length != 0) {
            Node<T> *current = head;
            while (current) {
                current->print();
                current = current->next;
            }
        }
        cout << endl;
    }
};
