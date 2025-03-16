#include <iostream>
#include <string>
using namespace std;


template <typename T> class Node {
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


template <typename T> class SpaceRoute {
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;

    public:
        SpaceRoute() {
            head = nullptr;
            tail = nullptr;
            length = 0;
        };  // Constructor
        ~SpaceRoute() {

        }; // Destructor

        void addWaypointAtBeginning(T& data) {
            Node<T>* newNode = new Node(data);
            //if the route is currently empty
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            //need to update head
            else {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            //change to length
            length++;
        }
        void addWaypointAtEnd(T& data){
            Node<T>* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        };
    void addWaypointAtIndex(int index, T& data){
        if (index < 0 || index > length + 1) {
            cout <<"Invalid Index"<< endl;
        }
        //we can just call methods already defined in the case that we want to add at the beginning or the end
        else if (index == 0) {
            addWaypointAtBeginning(data);
        }
        else if (index == length) {
            addWaypointAtEnd(data);
        }
        else {
            Node<T>* newNode = new Node<T>(data);
            Node<T>* curr = head;
            for (int i = 0; i < index-1; i++) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next->prev = newNode;
            curr->next = newNode;
            newNode->prev = curr;
            length++;
        }
    };
        void removeWaypointAtBeginning() {
            if (length == 0) {
                cout<<"There are currently no Waypoints"<<endl;
            }
            //need to check if there is a waypoint
            else if (length == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
                length--;
                //not only we have to delete the head but the head and tail
                //pointe must be reassigned
            }
            else {
                head = head->next;
                delete head->prev;
                head->prev = nullptr;
                length--;
            }
        };
        void removeWaypointAtEnd() {
            if (length == 0) {
                cout<<"There are currently no Waypoints"<<endl;
            }
            else if (length == 1) {
                delete tail;
                head = nullptr;
                tail = nullptr;
                length--;
            }
            else {
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
                length--;
            }
        };
        void removeWaypointAtIndex(int index) {
            //need to check if it is a valid index
            if ((index < 0) || (index > (length-1))) {
                cout <<"Invalid Index"<< endl;
            }
            else if (index == 0) {
                removeWaypointAtBeginning();
            }
            else if (index == length-1) {
                removeWaypointAtEnd();
            }
            else {
                Node<T>* curr = head;
                for (int i = 0; i< index; i++) {
                    curr = curr -> next;
                }
                //We need a temporary pointer in order to still have access to the node to be deleted
                Node<T>* temp = curr;
                curr = curr->prev;
                curr->next = curr->next->next;
                curr = curr->next;
                curr->prev = curr->prev->prev;
                delete temp;
                length--;
            }
        };
        void traverseForward(){
            if(length == 0){
                cout<<"No waypoints in route"<<endl;
            }
            else{
                Node<T>* currNode = head;
                while(currNode != nullptr){
                    currNode->print();
                    currNode = currNode->next;
                }
                cout<<"\n"<<endl;
            }


        };



        void traverseBackward(){
            if(length == 0){
                cout<<"No waypoints in route"<<endl;
            }
            else{
                Node<T>* currNode = tail;
                while(currNode != nullptr){
                    currNode->print();
                    currNode = currNode->prev;
                }
                cout<<"\n"<<endl;
            }
        }
        Node<T>* getWaypoint(int index){
            if(index < 0 || index >= length) {
                return nullptr;
            }
            else{
                Node<T>* currNode = head;
                for(int i = 0;i < index; i++){
                    currNode = currNode->next;
                }
                return currNode;
            }
        };
        void setWaypoint(int index, T& data){
            if(index < 0 || index >= length){
                cout<<"Invalid Input"<<endl;
            }
            else{
                removeWaypointAtIndex(index);
                addWaypointAtIndex(index,data);

            }
        };
        void print(){

                Node<T>* current = head;
                cout<<"Printing..."<<endl;
                while (current) {
                    current->print();
                    current = current->next;
                }
                cout << endl;
        }
};

