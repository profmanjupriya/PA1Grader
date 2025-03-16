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
    ~SpaceRoute() {
        Node<T> *current = head;
        while (current != nullptr) {
            Node<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        }

    }
    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node<T>(data);
        if (length == 0) { // empty list
            head = newNode;
            tail = newNode;
        }
        else { // snippet from linked list but also influencing the new previous node with doubly linked list
            newNode->next = head;
            head->prev = newNode;
            head = newNode;

        }
            length++;





    }
    void addWaypointAtEnd(T& data) {
        Node<T> *newNode = new Node<T>(data);


        Node<T> *temp = head;
        if (length == 0) { // empty list
            head = newNode;
            tail = newNode;
        }
        else { // using code from regular linked list implementation but tweaking a bit to be able to also update new tail pointer with doubly
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            tail = newNode;
        }
        length++;

    };
    Node<T>* get(int index) {
        if (index<0||index>length) { // out of index bounds
            return nullptr;
        }
        Node<T> *temp = head;
        for (int i = 0; i < index; i++) { // iterate through until at chosen index
            temp = temp->next;
        }
        return temp;
    }
    void addWaypointAtIndex(int index, T& data) {

        if (index<0||index>=length) { // index being chosen is not within the bounds
            cout << "Index is invalid" << endl;
            return;
        }

        if (index == 0) { // start of list
            addWaypointAtBeginning(data);
        }

        if (index == length) { // end of list
            addWaypointAtEnd(data);
        }

        else { // middle of list
            Node<T> *newNode = new Node<T>(data);
            Node<T> *temp = get(index-1);
            newNode->next = temp->next;
            newNode->prev = temp;
            newNode->next->prev = newNode;
            temp->next = newNode;
            length++;
        }




    }
    void removeWaypointAtBeginning() {
        if (length==0) { // edge case nothing in list
            cout << "There is no waypoint at the beginning" << endl;
            return;
        }
        else { // using delfirst method for singly linked list but also taking into account previous node
            Node<T> *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            length--;
        }


         {

        }
    }
    void removeWaypointAtEnd() { // setting to previous than making the previous the new last node then deleting original
        if (length==0) { // edge case nothing in list
            cout << "Empty list" << endl;
            return;
        }
        Node<T> *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        length--;







    }
    void removeWaypointAtIndex(int index) {

        if (index<0 || index>=length) { // out of index bound
           return;
        }
        else if (length==0) { // empty list
            return;
        }
        else if (index = 0) {
            removeWaypointAtBeginning();
        }

        else if (index==length-1) { // end of list
            removeWaypointAtEnd();
        }
        else { // using code from original single linked list for removing waypoints at middle with a bit of tweaking
            Node<T> *prev = get(index-1); // gets previous through subtracting one from chosen index and using get method to take it so you can use to replace index you chose to remove
            Node<T> *temp = prev->next; // sets temp to where your index is so you can remove it
            prev->next = temp->next;
            prev->next->prev = prev;

            //prev->next = temp->next; // moves previous next to the next node of where your index was set to so it can replace it when the index is deleted

            delete temp; // deleteing temp
            length--; // takes out from length the node that was deleted
        }
    }

    void traverseForward() {
        Node<T> *current = head;
        while (current != NULL) { // while list is not empty go through list and print
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void traverseBackward() { // starting at back and while current is not empty print and traverse
        Node<T> *current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }


    Node<T>* getWaypoint(int index) {
        if (length==0) { // empty
            cout << "No waypoint found" << endl;
        }
        if (index<0 || index>=length) { // out of index
            return nullptr;
        }
        else {
            Node<T> *temp = head;
            for (int i = 0; i < index; i++) { // same method as other get
                temp = temp->next;
            }
            cout << temp->data << " ";
            return temp;
        }
    }

    void setWaypoint(int index, T& data) {
        if (length==0) { // empty
            cout << "Empty list" << endl;
        }
        else if (index<0 || index>=length) { // index out of bound
            cout << "Waypoint is invalid" << endl;
        }
        else {
            Node<T> *temp = head;
            for (int i = 0; i < index; i++) { // traverse through index then when there replace with what you were setting
                temp = temp->next;

            }
            temp->data = data;

        }
    }

    void print() {
        Node<T> *current = head;
        while (current) { // while head is true
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

};

