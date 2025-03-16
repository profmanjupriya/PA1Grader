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
    }

    ~SpaceRoute() {
        Node<T>* curr = head;
        Node<T>* temp;
        for (int i = 0; i < size; i++) {
            temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }
    void addWaypointAtEnd(T& data){
        Node<T>* newNode = new Node(data);

        if (tail == nullptr) {
            tail = newNode;
            head = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }


    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index > size) {
            cerr << "Index out of bounds" << endl;
            return;
        }

        if (index == 0) {
            addWaypointAtBeginning(data);
            return;
        }
        if (index == size) {
            addWaypointAtEnd(data);
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        Node<T>* curr = head;

        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;

        ++size;
    }

    void removeWaypointAtBeginning() {
        if (head == nullptr) {
            cerr << "Empty space" << endl;
            return;
        }
        else {
            Node<T>* curr = head;
            head = head->next;
            head->prev = nullptr;
            delete curr;
            --size;

            if (size == 0) {
                tail = nullptr;
            }
        }
    }

    void removeWaypointAtEnd() {
        if (head == nullptr) {
            cerr << "Empty space" << endl;
            return;
        }
        else {
            Node<T>* curr = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete curr;
            --size;

            if (size == 0) {
                head = nullptr;
            }
        }
    }
    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= size) {
            cerr << "Index out of bounds" << endl;
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

        Node<T>* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        delete curr;
        --size;
    }

    void traverseForward() {
        Node<T>* curr = head;
        while (curr) {
            cout << curr->data << ", ";
            curr = curr->next;
        }
        cout << endl;
    }

    void traverseBackward() {
        Node<T>* curr = tail;
        for (int i = size - 1; i >= 0; i--) {
            cout << curr->data << ", ";
            curr = curr->prev;

        }
        cout << endl;
    }
    Node<T>* getWaypoint(int index) {
        if (index < 0 || index > size) {
            cerr << "Index out of bounds" << endl;
            return nullptr;
        }
        else if (size == 0) {
            cerr << "Empty space" << endl;
            return nullptr;
        }
        else {
            if (index == size - 1) {
                return tail;
            }
            else {
                Node<T>* curr = head;

                for (int i = 0; i < index; i++) {
                    curr = curr->next;
                }
                return curr;
            }
        }
    }
    void setWaypoint(int index, T& data) {
        if (index < 0 || index > size) {
            cerr << "Index out of bounds" << endl;
            return;
        }
        else if (size == 0) {
            cerr << "Empty space" << endl;
        }
        else {
            if (index == size - 1) {
                tail->data = data;
            }
            else {
                Node<T>* curr = head;

                for (int i = 0; i < index; i++) {
                    curr = curr->next;
                }
                curr->data = data;
            }
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

