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

    void addWaypointAtBeginning(T& data);
    void addWaypointAtEnd(T& data);
    void addWaypointAtIndex(int index, T& data);
    void removeWaypointAtBeginning();
    void removeWaypointAtEnd();
    void removeWaypointAtIndex(int index);
    void traverseForward();
    void traverseBackward();
    Node<T>* getWaypoint(int index);
    void setWaypoint(int index, T& data);
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

template<typename T> //constructor
SpaceRoute<T>::SpaceRoute(){
        head = nullptr;
        tail = nullptr;
}
    
template <typename T> //destructor
SpaceRoute<T>::~SpaceRoute(){
        Node<T>* current = head;
        while (current){
            Node<T>* next = current ->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
}
    
template <typename T>
void SpaceRoute<T>::addWaypointAtBeginning(T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void SpaceRoute<T>::addWaypointAtEnd(T& data){
    Node<T>* newNode = new Node<T>(data);

    if (head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template<typename T>
void SpaceRoute<T>::addWaypointAtIndex(int index, T& data){
    if (index == 0){
        addWaypointAtBeginning(data);
        return;
    }

    Node<T>* current = head;
    int currentCounter = 0;

    while (currentCounter < index){
        current = current->next;
        currentCounter ++;
    }

    if (current == nullptr){
        if (currentCounter == index){
            addWaypointAtEnd(data);
            return;
        }
    }
    Node<T>* newNode = new Node<T>(data);
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
}

template<typename T>
void SpaceRoute<T>::removeWaypointAtBeginning(){
    if (head == nullptr){
        cout<<"no plans yet."<<endl;
        return;
    }

    Node<T>* temp = head;
    if (head == tail){ //case of 1 node
        head = nullptr;
        tail = nullptr;
    }
    else{
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
}

template<typename T>
void SpaceRoute<T>::removeWaypointAtEnd(){

    if (head == nullptr){
        cout<<"no plans yet.."<<endl;
        return;
    }
    Node<T>* temp = tail;
    if (head == tail){ //case of 1 node
        head = nullptr;
        tail = nullptr;
    }
    else{
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
}

template<typename T>
void SpaceRoute<T>::removeWaypointAtIndex(int index){
    if (head == nullptr){
        cout<<"no plans yet..."<<endl;
        return;
    }
    if (index == 0) {
        removeWaypointAtBeginning();
        return;
    }
    
    Node<T>* temp = head;

    int tempCounter = 0;
    while (tempCounter < index){
        temp = temp->next;
        tempCounter++;
    }
    
    if (temp == nullptr) {
        return;
    }
    if (temp == tail){
        removeWaypointAtEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    delete temp;
}

template<typename T>
void SpaceRoute<T>::traverseForward(){
    Node<T>* current = head;
    while (current != nullptr){
        current->print();
        current = current->next;
    }
}

template<typename T>
void SpaceRoute<T>::traverseBackward(){
    Node<T>* current = tail;
    while (current != nullptr){
        current->print();
        current = current->prev;
    }
}

template<typename T>
Node<T>* SpaceRoute<T>::getWaypoint(int index){
    Node<T>* current = head;
    int currentCounter = 0;

    while(currentCounter < index){
        current = current->next;
        currentCounter++;
    }
    return current;
}

template<typename T>
void SpaceRoute<T>::setWaypoint(int index, T& data){
    Node<T>* node = getWaypoint(index);
    if (node != nullptr){
        node->data = data;
    }
}