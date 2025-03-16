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
    // Constructor
    SpaceRoute() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // Destructor
    ~SpaceRoute() {
        Node<T>* current = this->head;
        while (head) {
            head = head->next;
            delete current;
            current = head;
        }
    }

    void addWaypointAtBeginning(T& data) {
        if (length == 0) {
            defineFirst(data);
            return;
        }
        Node<T>* n = new Node<T>(data);
        head->prev = n;
        n->next = head;
        head = n;
        length++;
    }
    void addWaypointAtEnd(T& data) {
        if (length == 0) {
            defineFirst(data);
            return;
        }
        Node<T>* n = new Node<T>(data);
        tail->next = n;
        n->prev = tail;
        tail = n;
        length++;
    }
    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index > length) {
            throw out_of_range("index out of range. Length = " + to_string(length));
        }
        if (length == 0) {
            defineFirst(data);
            return;
        }
        if (index == 0) {
            addWaypointAtBeginning(data); //length++
            return;
        }
        if (index == length) {
            addWaypointAtEnd(data); //length++
            return;
        }
        Node<T>* n = new Node<T>(data);
        Node<T>* curr = head;
        for (int i = 0; i < index-1; ++i) {
            curr = curr->next;
        }
        n->next = curr->next;
        n->prev = curr;
        curr->next->prev = n;
        curr->next = n;
    }

    void removeWaypointAtBeginning() {
        if (length == 0) {
            throw logic_error("Cannot delete an element from an empty list");
        }
        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length = 0;
            return;
        }
        head->next->prev = nullptr;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void removeWaypointAtEnd() {
        if (length == 0) {
            throw logic_error("Cannot delete an element from an empty list");
        }
        if (length == 1) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            length = 0;
            return;
        }
        tail->prev->next = nullptr;
        Node<T>* temp = tail;
        tail = tail->prev;
        delete temp;
        length--;
    }

    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("index out of range. Length = " + to_string(length));
        }
        if (length == 0) {
            throw logic_error("Cannot delete an element from an empty list");
        }
        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length = 0;
            return;
        }
        if (index == 0) {
            removeWaypointAtBeginning(); //length--;
            return;
        }
        if (index == length-1) {
            removeWaypointAtEnd(); //length--;
            return;
        }
        Node<T>* curr = head;
        for (int i = 0; i < index-1; ++i) {
            curr = curr->next;
        }
        Node<T>* temp = curr->next;
        curr->next->next->prev = curr;
        curr->next = curr->next->next;
        delete temp;
        length--;
    }

    void traverseForward() {
        Node<T>* curr = head;
        while (curr) {
            curr->print();
            curr = curr->next;
        }
        cout << endl;
    }

    void traverseBackward() {
        Node<T>* curr = tail;
        while (curr) {
            curr->print();
            curr = curr->prev;
        }
        cout << endl;
    }

    Node<T>* getWaypoint(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("index out of range. Length = " + to_string(length));
        }
        if (length == 0) {
            throw logic_error("Cannot get an element from an empty list");
        }
        if (length == 1) {
            return head;
        }
        if (index == 0) {
            return head;
        }
        if (index == length-1) {
            return tail;
        }
        Node<T>* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr;
    }

    void setWaypoint(int index, T& data) {
        if (index < 0 || index >= length) {
            throw out_of_range("index out of range. Length = " + to_string(length));
        }
        if (length == 0) {
            throw logic_error("Cannot set an element in an empty list");
        }
        if (length == 1) {
            head->data = data;
        }
        if (index == 0) {
            head->data = data;
        }
        if (index == length-1) {
            tail->data = data;
        }
        Node<T>* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        curr->data = data;
    }

    void print(){
        Node<T>* current = head;
        while (current) {
            current->print();
            current = current->next;
        }
        cout << endl;
    }

private:
    //only use when list is empty
    void defineFirst(T& data) {
        if (length != 0) {
            throw logic_error("List must be empty to set the first element. List length = " + to_string(length));
        }
        Node<T>* n = new Node<T>(data);
        head = n;
        tail = n;
        length = 1;
    }

};