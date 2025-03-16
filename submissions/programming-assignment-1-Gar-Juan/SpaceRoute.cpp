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
    SpaceRoute(): head(nullptr), tail(nullptr){} // Constructor

    ~SpaceRoute() {
        Node<T>* current = head; // Set head node to current node
        while(current) {
            Node<T>* next = current->next;
            delete current; // Free the current node
            current = next; // Traverse to next node
        }
    } // Destructor

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data); //New node to dynamically allocated and initialized with data.
        // for empty list head pointer and tail pointer = newNode.
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }else {
            newNode->next = head; //set newNode's next pointer to head
            head-> prev = newNode; // Update head's previous pointer to newNode
            head = newNode; // Update newNode making it the first element of the list
        }
    } // End of addWaypointAtBeginning

    void addWaypointAtEnd(T& data) {
        Node<T>* newNode = new Node<T>(data); //New node to dynamically allocated and initialized with data.
        // for empty list tail pointer and tail pointer = newNode.
        if(tail == nullptr) {
            head = newNode;
            tail = newNode;
        }else {
            tail->next = newNode; // set newNode's next pointer to tail
            newNode->prev = tail; // Update tails previous pointer to newNode
            tail = newNode; // Update tail to be newNode
        }
    } // End of addWaypointAtEnd

    void addWaypointAtIndex(int index, T& data) {
        //Inserts node at the head if index is 0 or negative
        if (index <= 0) {
            addWaypointAtBeginning(data);
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; temp && i < index - 1; i++) {
            temp = temp->next;
        }
        // Insert at end if index is beyond the list
        if (temp == nullptr) {
            addWaypointAtEnd(data);
            return;
        }
        Node<T>* newNode = new Node<T>(data);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }// End of addWaypointAtIndex

    void removeWaypointAtBeginning() {
        if (head == nullptr) return; // Return if list is empty
        Node<T>* temp = head;
        head = head->next; // Update head pointer to next
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }// End of RemoveWaypointAtBeginning

    void removeWaypointAtEnd() {
        if (tail == nullptr) return; // Return if list is empty
        Node<T>* temp = tail;
        tail = tail->prev; // Update head pointer to next
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    } // End of removeWaypointAtEnd

    void removeWaypointAtIndex(int index) {
        if (head == nullptr || index < 0) return; // Return if list is empty

        if (index == 0) {
            removeWaypointAtBeginning();
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; temp && i < index; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return; // Return if index is out of bounds

        if (temp->prev) temp->prev->next = temp->next; // Update head if needed
        if (temp->next) temp->next->prev = temp->prev;  // Update tail if needed

        if (temp == tail) tail = temp->prev;

        delete temp;
    }// End of removeWaypointAtIndex

    void traverseForward() {
        Node<T>* current = head; // Start from the head of the list
        while (current) {
            current->print(); // Print current node
            current = current->next; // Move to next node
        }
        cout << endl;
    } // End of traverseForward

    void traverseBackward() {
        Node<T>* current = tail; // Start from the tail of the list
        while (current) {
            current->print(); // Print current node
            current = current->prev; // Move to previous node
        }
        cout << endl;
    } // End of traverseBackward

    Node<T>* getWaypoint(int index) {
        if (index < 0) return nullptr; // If invalid index return nullptr
        Node<T>* temp = head; // Start from head node
        for (int i = 0; temp && i < index; i++) {
            temp = temp->next;
        }
        return temp; // Returns nullptr if index is out of bounds

    } // End of getWaypoints

    void setWaypoint(int index, T& data) {
        Node<T>* node = getWaypoint(index); // Get the node at specified  index
        if (node) {
            node->data = data; // Update the node's data
        }
    } // End of setWaypoint

    void print(){
            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

