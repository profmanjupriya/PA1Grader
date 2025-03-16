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
    int routeLength;

public:
    SpaceRoute() {
        head = nullptr;
        tail = nullptr;
        routeLength = 0;
    };  // Constructor

    ~SpaceRoute() {
        Node<T>* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }; // Destructor

    void addWaypointAtBeginning(T& data) {
        Node<T>* newWayPoint = new Node<T>(data);

        if (routeLength == 0) {
            tail = newWayPoint;
        } else {
            head->prev = newWayPoint;
        }

        newWayPoint->next = head;
        head = newWayPoint;

        routeLength++;
    }

    void addWaypointAtEnd(T& data) {
        if (routeLength == 0) {
            addWaypointAtBeginning(data);
        } else {
            Node<T>* newWayPoint = new Node<T>(data);
            tail->next = newWayPoint;
            newWayPoint->prev = tail;
            tail = newWayPoint;
            routeLength++;
        }
    };

    void addWaypointAtIndex(int index, T& data) {
        if (index == 0) {
            addWaypointAtBeginning(data);
        } else if (index == routeLength) {
            addWaypointAtEnd(data);
        } else if (index < 0 || index > routeLength) {
            cout << "The given index is invalid" << endl;
        } else {
            Node<T>* newWayPoint = new Node<T>(data);
            Node<T>* afterWayPoint = getWaypoint(index);
            Node<T>* priorWayPoint = afterWayPoint->prev;

            newWayPoint->next = afterWayPoint;
            newWayPoint->prev = priorWayPoint;
            priorWayPoint->next = newWayPoint;
            afterWayPoint->prev = newWayPoint;
            routeLength++;
        }

    };

    void removeWaypointAtBeginning() {
        if (routeLength != 0) {
            Node<T>* temp = head;
            head = temp->next;
            delete temp;
            routeLength--;
        } else {
            cout << "The route is empty" << endl;
        }
    }

    void removeWaypointAtEnd() {
        if (routeLength != 0) {
            Node<T>* temp = tail;
            tail = temp->prev;
            delete temp;
            routeLength--;
        } else {
            cout << "The route is empty" << endl;
        }
    }

    void removeWaypointAtIndex(int index) {
        if (index == 0) {
            removeWaypointAtBeginning();
        } else if (index == routeLength - 1) {
            removeWaypointAtEnd();
        } else if (index < 0 || index >= routeLength) {
            cout << "The given index is invalid" << endl;
        } else {
            Node<T>* targetedWayPoint = getWaypoint(index);
            Node<T>* priorWayPoint = targetedWayPoint->prev;
            Node<T>* afterWayPoint = targetedWayPoint->next;

            priorWayPoint->next = afterWayPoint;
            afterWayPoint->prev = priorWayPoint;

            delete targetedWayPoint;
            routeLength--;
        }
    };

    void traverseForward() {
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void traverseBackward() {
        Node<T>* temp = tail;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->prev;
        }
    }

    Node<T>* getWaypoint(int index) {
        if (index < 0 || index >= routeLength) {
            cout << "The given index is invalid" << endl;
        } else {
            Node<T>* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
    };


    void setWaypoint(int index, T& data) {
        if (index < 0 || index >= routeLength) {
            cout << "The given index is invalid" << endl;
        } else if (routeLength == 0) {
            cout << "The route is empty" << endl;
        } else {
            Node<T>* modifyThis = getWaypoint(index);
            modifyThis->data = data;
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

