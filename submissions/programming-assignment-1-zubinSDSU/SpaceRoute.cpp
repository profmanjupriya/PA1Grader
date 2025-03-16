#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T d) : data(d), next(nullptr), prev(nullptr) {}
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
    T data;

public:
    SpaceRoute(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;

    }   // Constructor


    ~SpaceRoute() {

        Node<T>* curr = this->head;

        while (head){
            head = head->next;
            delete curr;
            curr = head;

        }

    }



    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        newNode->prev = nullptr;




        if (head != nullptr) {

            head->prev = newNode;
        }
        else {
            tail = newNode;
        }

        head = newNode;
        length++;
    }


    void addWaypointAtEnd(T& data) {
        Node<T> *newNode = new Node<T>(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;

            newNode->prev = nullptr;
            newNode->next = nullptr;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;


    }

    void addWaypointAtIndex(int index, T& data) {

        if (index < 0 || index > length) {
            return;
        }

        if (index == 0) {
            addWaypointAtBeginning(data);
            return;
        }
        if (index == length) {
            addWaypointAtEnd(data);
            return;
        }



        Node<T>* temp;
        if (index < length/2) {
            temp = head;
            for (int i = 0; i < index-1; i++) {
                temp = temp->next;
            }

        }
        else {
            temp = tail;
            for (int i = length-1; i > index-1; i--) {
                temp = temp->prev;
            }
        }



        Node<T>* newNode = new Node<T>(data);
        Node<T>* tempNext = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = tempNext;

        if (tempNext != nullptr) {
            tempNext->prev = newNode;
        }




        length++;

    }

    void removeWaypointAtBeginning() {

        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T> *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        length--;



    }


    void removeWaypointAtEnd() {

        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;

        }
        else {
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        length--;

    }

    void removeWaypointAtIndex(int index) {
        if (index < 0 || index >= length) {
            return;
        }

        if (index == 0) {
            removeWaypointAtBeginning();
            return;
        }
        if (index == length-1) {
            removeWaypointAtEnd();
            return;
        }




        Node<T>* temp;
        if (index < length/2) {
            temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }

        }
        else {
            temp = tail;
            for (int i = length-1; i > index; i--) {
                temp = temp->prev;
            }
        }



        Node<T> *tempNext = temp->next;
        Node<T> *tempPrev = temp->prev;

        if (tempPrev != nullptr) {
            tempPrev->next = temp->next;
        }
        if (tempNext != nullptr) {
            tempNext->prev = temp->prev;
        }

        delete temp;



        length--;


    }

    void traverseForward() {

        if (head == nullptr) {
            return;
        }

        Node<T>* curr = head;
            while (curr != nullptr) {
                cout << curr->data << " ";
                curr = curr->next;
            }
    }




    void traverseBackward() {
        if (head == nullptr) {
            return;
        }
        Node<T>* curr = tail;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
    }



    Node<T>* getWaypoint(int index) {
        Node<T>* temp;


        if (index >= length || index < 0) {
            return nullptr;
        }


        if (index < length/2) {
            temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }

        }
        else {
            temp = tail;
            for (int i = length-1; i > index; i--) {
                temp = temp->prev;
            }
        }

        return temp->data;


    }






    void setWaypoint(int index, T& data) {

        if (index >= length || index < 0) {
            return;
        }


        Node<T>* temp;
        if (index < length/2) {
            temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }

        }
        else {
            temp = tail;
            for (int i = length-1; i > index; i--) {
                temp = temp->prev;
            }
        }

        temp->data = data;



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

