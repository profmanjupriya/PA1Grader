#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T* data;
    Node* next;
    Node* prev;

    Node(T* d) : data(d), next(nullptr), prev(nullptr) {}
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
    SpaceRoute(T* data) {
        // Constructor
        Node<T> *newNode = new Node<T>(data);
        head = newNode;
        tail = newNode;
        length=1;
    }
    ~SpaceRoute() {
        // Destructor
        Node<T> *temp = head;
        while(head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

        void addWaypointAtBeginning(T* data) {
            Node<T>* newNode = new Node<T> (data);
            if (length==0){
                head= newNode;
                tail= newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head= newNode;
            }
            length++;
        }
        void addWaypointAtEnd(T* data) {
            Node<T> *newNode = new Node<T> (data);
            if (length==0) {
                tail=newNode;
                head=newNode;
            }else {
                tail->next = newNode;
                newNode->prev = tail;
                tail=newNode;
            }
            length++;
        }
        void addWaypointAtIndex(int index, T* data) {
            if (index<0 || index>length) {
                cout<<"Invalid index!"<<endl;
                return;
            }else if (index==0) {
                addWaypointAtBeginning(data);
                return;
            }else if (index==length) {
                addWaypointAtEnd(data);
                return;
            }
            Node<T> *newNode = new Node<T> (data);
            Node<T> *temp = getWaypoint(index-1);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next= newNode;
            length++;
        }
        void removeWaypointAtBeginning(){
            if (length==0) {
                return;
            }
            Node<T> *temp = head;
            if (length==1) {
                head= nullptr;
                tail= nullptr;
            }else {
                head=head->next;
                head->prev=nullptr;
            }
            delete temp;
            length--;
        }
        void removeWaypointAtEnd(){
            if (length==0) {
                return;
            }
            Node<T> *temp = tail;
            if (length==1) {
                head= nullptr;
                tail= nullptr;
            } else {
                temp=tail;
                tail=temp->prev;
                tail->next=nullptr;
            }
            delete temp;
            length--;
        }

        void removeWaypointAtIndex(int index) {
            if (index<0 || index>=length) {
                return;
            } if (index==0) {
                removeWaypointAtBeginning();
                return;
            } if (index==length-1) {
                removeWaypointAtEnd();
                return;
            }
            Node<T> *prevNode = getWaypoint(index-1);
            Node<T> *temp = prevNode->next;
            temp->next->prev = prevNode;
            delete temp;
            length--;
        }
        void traverseForward() {
            Node<T> *temp = head;
            while (temp) {
                temp->print();
                temp = temp->next;
            }
        }

        void traverseBackward() {
            Node<T> *temp = tail;
            while (temp) {
                temp->print();
                temp= temp->prev;
            }
        }

        Node<T>* getWaypoint(int index) {
            if (index<0 || index >= length)
                return nullptr;

                Node<T>* temp = head;
                for (int i=0; i<index; i++) {
                    temp = temp->next;
                }
                return temp;
            }


        void setWaypoint(int index, T* data) {
            Node<T> *temp = getWaypoint(index);
            if (temp) {
                temp->data = data;
                return;
            }
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



