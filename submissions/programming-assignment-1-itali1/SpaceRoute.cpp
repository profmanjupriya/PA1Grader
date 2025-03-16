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
    //keep getting an error therefore, I changed the constructor or destructor. Not sure how to fix the error without making this change
    SpaceRoute(): head(nullptr), tail(nullptr) {}
    ~SpaceRoute() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            Node<T>* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if(head == nullptr) {
            head = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }

    }
    void addWaypointAtEnd(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if(head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void addWaypointAtIndex(int index, T& data) {
        Node<T>* newNode = new Node<T>(data);
        if(index < 0 || index > head->data.size()) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if(index == 0){
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        if(index == head->data.size()) {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }else {
            Node<T>* temp = head;
            for(int i=0; i<index-1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next->prev = newNode;
        }
        return;
    }
    void removeWaypointAtBeginning(){
        if(head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "There are no points to remove" << endl;
        }
    }

    void removeWaypointAtEnd() { //when printing, a lot of symbols print after. NOTE: Has happened before, need to check later
        if(head != nullptr) {
            Node<T>* temp = tail;
            tail = tail->prev;
            delete temp;
        }else {
            cout << "There are no points to remove" << endl;
        }
    }
    void removeWaypointAtIndex(int index) {
        if(index < 0 || index > head->data.size()) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if(index == 0) {
            if(head != nullptr) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            } else {
                cout << "There are no points to remove" << endl;
            }
            return;
        }

        if(index == head->data.size()) {
            if(head != nullptr) {
                Node<T>* temp = tail;
                tail = tail->prev;
                delete temp;
            }else {
                cout << "There are no points to remove" << endl;
            }
            return;
        }else {
            Node<T>* temp = head;
            for(int i=0; i<index; i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }

    }
    void traverseForward() {
        if(head != nullptr) {
            Node<T>* temp = head;
            while(temp != nullptr) {
                temp->print();
                temp = temp->next;
            }
        }
    }
    void traverseBackward() {
        if(head != nullptr) {
            Node<T>* temp = tail;
            while(temp != nullptr) {
                temp->print();
                temp = temp->prev;
            }
        }
    }
    Node<T>* getWaypoint(int index) {
        if(index < 0 || index > head->data.size()) {
            return nullptr;
        }
        Node<T>* temp = head;
        for(int i=0; i<=index; i++) {
            temp = temp->next;
        }
        return temp;
    }
    void setWaypoint(int index, T& data) {
        if(index < 0 || index > head->data.size()) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if(index == head->data.size()) {
            tail->data = data;
            return;
        }
        else if (index == 0){
            head->data = data;
            return;
        }
        Node<T>* temp = head;
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
        temp->data = data;
        return;
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

