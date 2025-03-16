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
    SpaceRoute() {
        this->length = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }
    SpaceRoute(T *value) {
        this->length = 1;
        this->head = new Node<T>(*value);
        this->tail = head;
    }
    ~SpaceRoute() {
        while (this->head != nullptr) {
            this->head = this->head->next;
            delete this->head->prev;
        }
        delete this->head;
        length = 0;
    }

    void addWaypointAtBeginning(T& data) {
        if (head == nullptr) {
            head = new Node<T>(data);
            tail = head;
            length++;
        }
        else {
            Node<T>* temp = new Node<T>(data);
            temp->next = head;
            head->prev = temp;
            head = temp;
            length++;
        }

    }

    void addWaypointAtEnd(T& data) {
        if (head == nullptr) {
            head = new Node<T>(data);
            tail = head;
            length++;
        } else {
            tail->next = new Node<T>(data);
            tail->next->prev = tail;
            tail = tail->next;
            length++;
        }
    }

    void addWaypointAtIndex(int index, T& data) {

        if (index < 0 || index > length) {
            cout << "Index out of range" << endl;
        } else if (index == 0) {
            addWaypointAtBeginning(data);
        } else if (index == length) {
            addWaypointAtEnd(data);
        } else {
            Node<T>* cur = head;
            for (int i = 0; i < index - 1; i++) { // cur will be pointing at the node right before the added node
               cur = cur->next;
            }
            Node<T>* temp = new Node<T>(data);
            temp->next = cur->next;
            cur->next = temp;
            temp->prev = cur;
            temp->next->prev = temp;
            length++;
        }
    }

    void removeWaypointAtBeginning() {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            length--;
        } else {
            cout << "List is empty" << endl;
        }
    }

    void removeWaypointAtEnd() {
        if (head != nullptr) {
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            length--;
        } else {
            cout << "List is empty" << endl;
        }
    }

    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of range" << endl;
        } else if (index == 0) {
            removeWaypointAtBeginning();
        } else if (index == length - 1) {
            removeWaypointAtEnd();
        } else {
            Node<T>* cur = head;
            for (int i = 0; i < index ; i++) { // cur will point to the node to delete
                cur = cur->next;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            length--;
        }
    }

    void traverseForward() {
        cout << "front ";
        if (head != nullptr) {
            Node<T>* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << "back" << endl;
    }

    void traverseBackward() {
        cout << "back ";
        if (head != nullptr) {
            Node<T>* temp = tail;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->prev;
            }
        }
        cout << "front" << endl;
    }

    Node<T>* getWaypoint(int index) {
        if (index >= 0 && index < length) {
            Node<T>* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
        return nullptr;
    }

    void setWaypoint(int index, T& data) {
        if (index >= 0 && index < length) {
            Node<T>* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->data = data;
        } else {
            cout << "Index out of range" << endl;
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

