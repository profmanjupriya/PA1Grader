#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr){}

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
    // Constructor;
    SpaceRoute () : head(nullptr), tail(nullptr), length(0) {
    };

    // Destructor
    ~SpaceRoute() {
        Node<T> *temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node<T>(data);

        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            Node<T> *temp = head;
            newNode->next = temp;
            head->prev = newNode;
            newNode->prev = nullptr;
            head = newNode;

        }
        length++;
    }

    void addWaypointAtEnd(T& data) {
        Node<T> *newNode = new Node<T>(data);
        Node<T> *temp = tail;
        if (length == 0) {
            head = newNode;
            head->next = nullptr;
            tail = newNode;
            tail->prev = nullptr;
        }
        else {
            tail->next = newNode;
            newNode->next = nullptr;
            tail->prev = temp;
            tail = newNode;
        }
        length++;
    }

    void addWaypointAtIndex(int index, T& data) {
        if (index<0 || index>length) {
            cout<<"index is invalid"<<endl;
            return;
        }
        if (index==0) {
            addWaypointAtBeginning(data);
        }
        if (index==length) {
            addWaypointAtEnd(data);
        }

        else {
            Node<T>* newNode = new Node<T>(data);
            Node<T>* temp = getWaypoint(index-1);
            Node<T>* temp2 = getWaypoint(index);
            temp->next = newNode;
            newNode->next = temp2;
            length++;
        }

    }

    void removeWaypointAtBeginning() {
        if (head == nullptr) {
            cout<<"The list is empty"<<endl;
            return;
        }

        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void removeWaypointAtEnd() {
        if (length == 0)
            return;
        Node<T> *temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T> *pre = head;
            while (temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void removeWaypointAtIndex(int index) {
        if (index<0 || index>=length) {
            cout<<"Index is invalid"<<endl;
            return;
        }

        if (index==0) {
            removeWaypointAtBeginning();
        }

        else  {
            Node<T> *temp = getWaypoint(index-1);
            Node<T> *temp2 = getWaypoint(index);
            temp->next = temp2->next;
            temp2->prev = temp;
            length--;
        }

    }

    void traverseForward() {
        Node<T> *temp = head;
        if (temp == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        while (temp->next!=NULL)
            temp = temp->next;
        tail = temp;
        print();
    }

    void traverseBackward() {
        Node<T> *temp = tail;;
        if (temp == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        while (tail != nullptr) {
            cout << temp->data << " ";
            tail = temp->prev;
        }
        cout << endl;
    }

    Node<T>* getWaypoint(int index) {
        if ( index < 0 || index >= length )
            return nullptr;
        Node<T>* temp =head;
        for (int i = 0 ; i < index ; i++){
            temp = temp->next;
        }
        return temp;
    }

    void setWaypoint(int index, T& data) {
        if ( index < 0 || index >= length ) {
            cout<<"Index is invalid"<<endl;
        }

        Node<T>* temp =head;
        for (int i = 0 ; i < index ; i++){
            temp = temp->next;
        }
        temp->data = data;
    }
    void print(){
            Node<T>* current = head;
            while (current!=NULL) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};


