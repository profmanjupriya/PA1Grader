#include <iostream>
#include <list>
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
    SpaceRoute(){};  // Constructor
    ~SpaceRoute(){}; // Destructor


    void addWaypointAtBeginning(T& data){
    Node<T>* wayPoint = new Node<T>(data);
        wayPoint->next = head;
        wayPoint-> prev = nullptr;
        if (head != nullptr) {
            head->prev = wayPoint;

        }else {
            tail = wayPoint;
        }
        head = wayPoint;
}

    void addWaypointAtEnd(T& data) {
        Node<T>* wayPoint = new Node<T>(data);
        if (head == nullptr) {
            head = wayPoint;
            tail = wayPoint;
        } else {
            tail->next = wayPoint;
            wayPoint->prev = tail;
            tail = wayPoint;
        }
    }



     void addWaypointAtIndex(int index, T& data) {

        if (index<0) {
            cout << "index out of bounds" << endl;
            return;
        }
        //create new node and insert at beginning
        Node<T>* wayPoint = new Node<T>(data);
        if (index == 0) {
            wayPoint->next = head;
            wayPoint-> prev = nullptr;
            if (head != nullptr) {
                head->prev = wayPoint;
            }else {
                tail = wayPoint;
            }
            head = wayPoint;
        }
        //go to node at index n-1
        Node<T>* curr = head;
        for (int i=0; i<index-1 && curr!=nullptr;i++) {
            curr = curr->next;
        }
        //check if index is out of bounds
        if (curr == nullptr) {
            cout<<"index out of bounds"<<endl;
            delete wayPoint;
        }
        //insert new waypoint
        wayPoint->next = curr->next;
        wayPoint-> prev = curr;
        if (curr->next != nullptr) {
            curr->next->prev = wayPoint;
        } else {
            tail = wayPoint;
        }
        curr->next = wayPoint;
    }

    void removeWaypointAtBeginning() {
        if (head == nullptr) {
            cout<<"head is empty"<<endl;
            return;
        }
        Node<T>* temp = head;
        head=head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }else {
            tail = nullptr;
        }
        delete temp;
    }

     void removeWaypointAtEnd() {
        if (head == nullptr) {
            cout<<"list is empty"<<endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head= nullptr;
            tail=nullptr;
            return;
        }
        Node<T>* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        if (curr->prev != nullptr) {
            curr->prev->next = nullptr;
        }
        tail=curr->prev;
        delete curr;

    }

    void removeWaypointAtIndex(int index) {
        if (index < 0) {
            cout << "index out of bounds" << endl;
            return;
        }
        if (head == nullptr) {
            cout<<"head is empty"<<endl;
            return;
        }
        if (index == 0) {
            Node<T>* temp = head;
            head=head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }else {
                tail = nullptr;
            }
            delete temp;
        }
        Node<T>* curr = head;
        for (int i=0;i<index-1 && curr!=nullptr;i++) {
            curr=curr->next;
        }
        if (curr == nullptr) {
            cout<<"index out of bounds"<<endl;
            return;
        }
        if (curr->next == nullptr) {
            tail = curr->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }else {
                head = nullptr;
            }
            delete curr;
            return;
        }

        Node<T>* temp = curr->next;
        curr->next = temp->next;
        temp->next->prev = curr;
        delete temp;

    }


     void traverseForward() {
        if (head == nullptr) {
            cout<<"list is empty"<<endl;
            return;
        }
        Node<T>* curr = head;
        while (curr != nullptr) {

            cout << curr->data << " ";
            curr = curr-> next;
        }
        cout << endl;
    }

    void traverseBackward() {
        if (head == nullptr) {
            cout<<"list is empty"<<endl;
            return;
        }
        Node<T>* curr = tail;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }

    Node<T>* getWaypoint(int index) {
        if (index < 0) {
            cout<<"index out of bounds"<<endl;
            return nullptr;
        }
        Node<T>* curr = head;
        int counter = 0;
        while (curr != nullptr) {
            if (counter == index) {
                cout << "Node at index " << index << ": " << curr->data << endl;
                return curr;
            }
            counter++;
            curr = curr->next;
        }
        cout<<"index out of bounds"<<endl;
        return nullptr;
    }

    void setWaypoint(int index, T& data) {
        if (index < 0) {
            cout<<"index out of bounds"<<endl;
            return;
        }
        Node<T>* curr = head;
        int counter = 0;
        while (curr != nullptr) {
            if (counter == index) {
                 curr->data = data;
                return;
            }
            counter++;
            curr = curr->next;
        }
        cout<<"index out of bounds"<<endl;
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

