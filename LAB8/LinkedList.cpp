#include <iostream>
#include <vector>
#include "LinkedList.h"

using std::cout, std::cin, std::endl, std::vector;

// Part 1
LinkedList::LinkedList() : head(nullptr){} // Part 1

void LinkedList::print() { // Part 1
    if (head == nullptr){
        cout << "Empty List" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr){
        cout << current->num << " ";
        current = current ->next;
    }
    cout << endl;
}


bool LinkedList::hasValue(int val) { // optional practice / challenge (Part 1)
    return false; // update to provide correct boolean value
}

void LinkedList::printReverse(){ // optional practice / challenge (Part 1)
}

// Part 2
void LinkedList::insertHead(int val) { // Part 2
    Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } 
        else {
            newNode->next = head;
            head = newNode;
        }
}


void LinkedList::insertAfter(int val, int valToInsertAfter) { // Part 2
    Node* current = head;
        while (current != nullptr && current->num != valToInsertAfter) {
            current = current->next;
        }

        if (current == nullptr) {
            Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
        } else {
            Node* newNode = new Node(val);
            newNode->next = current->next;
            current->next = newNode;

            if (current == tail) {
                tail = newNode;
            }
        }
}



void LinkedList::insertTail(int val) { // optional practice / challenge (Part 2)
}  

LinkedList::LinkedList(int val) { // optional practice / challenge (Part 2)
}

LinkedList::LinkedList(std::vector<int> nums) { // optional practice / challenge (Part 2)
}

// Part 3
void LinkedList::insertBefore(int val, int valToInsertBefore) { // Part 3
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } 
    else if (head->num == valToInsertBefore) {
        newNode->next = head;
        head = newNode;
    } 
    else {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->num != valToInsertBefore) {
            previous = current;
            current = current->next;
        }
        if (current == nullptr) {
            tail->next = newNode;
            tail = newNode;
        }
        else {
            previous->next = newNode;
            newNode->next = current;
        }
    }
}   

void LinkedList::remove(int val) { // Part 3
    if (head == nullptr) {
        return;
    }
    if (head->num == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr; // List is now empty
        }
        return;
    }
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr && current->num != val) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        return;
    }
    previous->next = current->next;
    if (current == tail) {
        tail = previous;
    }
    delete current;
};


void LinkedList::removeAfter(int valToFindAndRemoveValAfter) { // optional practice / challenge (Part 3)
}

void LinkedList::removeBefore(int valToFindAndRemoveValBefore) { // optional practice / challenge (Part 3)
}

void LinkedList::removeAll(int val) { // optional practice / challenge (Part 3)
}

// Part 4
void LinkedList::clear() { // Part 4
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList() {
     // Part 4
     clear();
}

LinkedList::LinkedList(const LinkedList& src) { // Part 4
    Node* current = src.head;
    while (current != nullptr) {
        insertAfter(current->num, tail ? tail->num : 0);
        current = current->next;
    }
}



LinkedList& LinkedList::operator=(const LinkedList& src) { // Part 4
    if (this == &src) {
        return *this; 
    }
    clear();
    Node* current = src.head;
    while (current != nullptr) {
        insertAfter(current->num, tail ? tail->num : 0);
        current = current->next;
        }
        return *this;

}

// Provided
void LinkedList::makeTestList() {
    // a really bad way to create a list, 
    //    but it will let you practice traversing before building your own list.
    Node* x = new Node(5);
    head = x;
    x = new Node(14);
    head->next = x;
    x = new Node(8);
    head->next->next = x;
    x = new Node(33);
    head->next->next->next = x;
    tail = x;
} 