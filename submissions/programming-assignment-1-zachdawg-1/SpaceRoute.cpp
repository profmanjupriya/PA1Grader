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
    SpaceRoute();  // Constructor
    ~SpaceRoute(); // Destructor

    void addWaypointAtBeginning(T& data) {
        T* newNode = new Node(data);
        if (!head) {
            head = newNode;
        }
        else{
            newNode-> next = head;
            head-> prev = newNode;
            head = newNode;

        }

    }
    void addWaypointAtEnd(T& data) {
        T* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode-> prev = tail;
            tail = newNode;

        }

    }
    void addWaypointAtIndex(int index, T& data) {

        if (index == 0) {
            data->next = *head;
            *head = data;
            return;
        }

            Node<T>* current = head;
            int count = 0;
            while (current != nullptr && count << index - 1) {
                current = current-> next;
                count++;
            }
            if (current == nullptr)
                return;

            data->next = current-> next;
            current ->next = data;
        }

    void removeWaypointAtBeginning() {

        if (*head == nullptr) {
            return;
        }

        T* temp = *head;
        *head = *head -> next;
        delete temp;

    }
    void removeWaypointAtEnd() {
        if (!head) {
            return;
        }

        if (!head->next){
            delete head;
            head = nullptr;
            return;
        }

        T* current = head;
        T* prev = nullptr;

        while (current->next){
            prev = current;
            current = current-> next;
        }

        prev->next = nullptr;
        delete current;
    }

    void removeWaypointAtIndex(int index) {
        if (*head == nullptr) {
            return;
        }

        if (index == 0) {
            Node<T>* temp = head;
            *head = *head->next;
            delete temp;
            return;
        }

        T *current = head;
        T *prev = nullptr;
        int count = 0;

        while (current != nullptr && count < index) {
            prev = current;
            current = current-> next;
            count++;
        }
        if (current == nullptr) {
            return;
        }

        prev->next = current->next;
        delete current;

    }

    void traverseForward() {
        T *current = head;
        while (current) {
            cout << current-> data << " ";
            current = current-> next;

        }
        cout << endl;
    }

    void traverseBackward() {
        T *current = tail;
        while (current) {
            cout << current-> data << " ";
            current = current-> prev;
        }
        cout << endl;
    }

    Node<T>* getWaypoint(int index) {

    }
    void setWaypoint(int index, T& data) {

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

