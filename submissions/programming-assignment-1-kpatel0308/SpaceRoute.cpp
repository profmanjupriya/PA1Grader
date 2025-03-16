#include "SpaceRoute.h" // Include the header file to connect declaration and definition

// Node constructor
template <typename T>
Node<T>::Node(T d) : data(d), next(nullptr), prev(nullptr) {}

// Node print method
template <typename T>
void Node<T>::print() {
    std::cout << data << " ";
}

// SpaceRoute constructor
template <typename T>
SpaceRoute<T>::SpaceRoute() : head(nullptr), tail(nullptr) {}

// SpaceRoute destructor (to free memory)
template <typename T>
SpaceRoute<T>::~SpaceRoute(){
    Node<T>* current = head;
    while (current) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
}

// Add waypoint at the beginning
template<typename T>
void SpaceRoute<T>::addWaypointAtBeginning(T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Add waypoint at the end
template <typename T>
void SpaceRoute<T>::addWaypointAtEnd(T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Add waypoint at a specific index
template <typename T>
void SpaceRoute<T>::addWaypointAtIndex(int idx, T& data) {
    if (idx < 0) return;

    if (idx == 0) {
        addWaypointAtBeginning(data);
        return;
    }

    Node<T>* newNode = new Node<T>(data);
    Node<T>* current = head;
    int count = 0;

    while (current && count < idx - 1) {
        current = current->next;
        count++;
    }

    if (current) {
        newNode->next = current->next;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;

        if (!newNode->next) {
            tail = newNode;
        }
    }
}

// Remove the first waypoint
template <typename T>
void SpaceRoute<T>::removeWaypointAtBeginning() {
    if (!head) return;

    Node<T>* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;

    delete temp;

    if (!head) tail = nullptr; // If list is now empty, set tail to nullptr
}

// Remove the last waypoint
template <typename T>
void SpaceRoute<T>::removeWaypointAtEnd() {
    if (!tail) return;

    Node<T>* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;

    delete temp;

    if (!tail) head = nullptr;  // If list is now empty, set head to nullptr
}

// Remove a waypoint at a specific index
template <typename T>
void SpaceRoute<T>::removeWaypointAtIndex(int idx){
    if (idx < 0 || !head) return;

    if (idx == 0) {
        removeWaypointAtBeginning();
        return;
    }

    Node<T>* current = head;
    int count = 0;

    while (current && count < idx) {
        current = current->next;
        count++;
    }

    if (current) {
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;

        delete current;

        if (!current->next) tail = current->prev;  // Update tail if needed
    }
}

// Traverse the route forward (from head to tail)
template <typename T>
void SpaceRoute<T>::traverseForward() {
    Node<T>* current = head;
    while (current) {
        current->print();
        current = current->next;
    }
    std::cout << std::endl;
}

// Traverse the route backward (from tail to head)
template <typename T>
void SpaceRoute<T>::traverseBackward() {
    Node<T>* current = tail;
    while (current) {
        current->print();
        current = current->prev;
    }
    std::cout << std::endl;
}

// Get a waypoint at a specific index
template <typename T>
Node<T>* SpaceRoute<T>::getWaypoint(int idx) {
    if (idx < 0) return nullptr;

    Node<T>* current = head;
    int count = 0;

    while (current && count < idx) {
        current = current->next;
        count++;
    }

    return current;
}

// Set a waypoint's data at a specific index
template <typename T>
void SpaceRoute<T>::setWaypoint(int idx, T& data) {
    Node<T>* node = getWaypoint(idx);
    if (node) {
        node->data = data;
    }
}

// Print the entire route
template <typename T>
void SpaceRoute<T>::print() {
    Node<T>* current = head;
    while (current) {
        current->print();
        current = current->next;
    }
    std::cout << std::endl;
}
