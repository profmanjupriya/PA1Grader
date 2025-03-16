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
   CelestialNode(const string& n, double d, const string& log)
       : name(n), distance_from_earth(d), mission_log(log) {}


   const string& getName() const { return name; }
   double getDistance() const { return distance_from_earth; }
   const string& getMissionLog() const { return mission_log; }


   void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};


template <typename T>
class SpaceRoute {
private:
   Node<T>* head;
   Node<T>* tail;
   int length = 0;


public:
   SpaceRoute() : head(nullptr), tail(nullptr) {}


   ~SpaceRoute() {


       Node<T>* current = head;
       while (current) {
           Node<T>* temp = current;
           current = current->next;
           delete temp;
       }
   }


       void addWaypointAtBeginning(T& data) {
       Node<T>* newNode = new Node<T>(data);
       if (length == 0) {
           head = tail = newNode;
       } else {
           newNode->next = head;
           head->prev = newNode;
           head = newNode;
       }
       length++;
   }


   void addWaypointAtEnd(T& data) {
       Node<T>* newNode = new Node<T>(data);
       if (length == 0) {
           head = tail = newNode;
       } else {
           tail->next = newNode;
           newNode->prev = tail;
           tail = newNode;
       }
       length++;
   }


   void addWaypointAtIndex(int index, T& data) {
       if (index < 0 || index > length) {
           cout << "Index is invalid" << endl;
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


       Node<T>* newNode = new Node<T>(data);
       Node<T>* temp = head;
       for (int i = 0; i < index; i++) {
           temp = temp->next;
       }


       newNode->next = temp;
       newNode->prev = temp->prev;
       temp->prev->next = newNode;
       temp->prev = newNode;
       length++;
   }


   void removeWaypointAtBeginning() {
       if (!head) {
           cout << "No waypoints in the list." << endl;
           return;
       }
       Node<T>* temp = head;
       head = head->next;
       if (head)
           head->prev = nullptr;
       else
           tail = nullptr;
       delete temp;
       length--;
   }


   void removeWaypointAtEnd() {
       if (!tail) {
           cout << "No waypoints in the list." << endl;
           return;
       }
       Node<T>* temp = tail;
       tail = tail->prev;
       if (tail)
           tail->next = nullptr;
       else
           head = nullptr;
       delete temp;
       length--;
   }


   void removeWaypointAtIndex(int index) {
       if (index < 0 || index >= length) {
           cout << "Index is invalid" << endl;
           return;
       }


       if (index == 0) {
           removeWaypointAtBeginning();
           return;
       }


       if (index == length - 1) {
           removeWaypointAtEnd();
           return;
       }


       Node<T>* temp = getWaypoint(index);
       if (!temp) {
           return;
       }


       temp->prev->next = temp->next;
       temp->next->prev = temp->prev;
       delete temp;
       length--;
   }


   void traverseForward() {
       Node<T>* current = head;
       while (current) {
           current->print();
           current = current->next;
       }
       cout << endl;
   }


   void traverseBackward() {
       Node<T>* current = tail;
       while (current) {
           current->print();
           current = current->prev;
       }
       cout << endl;
   }


   Node<T>* getWaypoint(int index) {
       if (index < 0 || index >= length) {
           cout << "Index is invalid." << endl;
           return nullptr;
       }


       Node<T>* temp = head;
       for (int i = 0; i < index; i++) {
           temp = temp->next;
       }
       return temp;
   }


   void setWaypoint(int index, T& data) {
       Node<T>* temp = getWaypoint(index);
       if (!temp) {
           return;
       }
       temp->data = data;
   }


   void print() {
       Node<T>* current = head;
       while (current) {
           current->print();
           current = current->next;
       }
       cout << endl;
   }
};

