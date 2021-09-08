//
// Created by Braiden Hook on 9/7/21.
//
#include <fstream>
#include "LinkedList.h"
using namespace std;
// Default Constructor
LinkedList::LinkedList() {

    this->head = nullptr;
    this->tail = nullptr;
    this->length = new int (0);
}
// Destructor
LinkedList::~LinkedList() {

    Node *temp = this->head;
    //transversing through the list deleting each node
    while (temp != nullptr){
        Node *deletedNode = temp;
        temp = temp->next;
        delete deletedNode;
    }
    this->head = nullptr;
    this->tail = nullptr;
}
// Copy Constructor
LinkedList::LinkedList(const LinkedList &copy){

    this->head = nullptr;
    this->tail = nullptr;
    this->length = new int(0);

    Node *curr = copy.head;
    //transversing through list copying each node and appending it
    while (curr != nullptr){
        append(curr->data);
        curr = curr->next;
        length = copy.length;
    }
}
// Copy Assignment
LinkedList &LinkedList::operator=(const LinkedList &copy){
    //if not a copy
    if (this != &copy) {
        delete head; //will delete head
        delete tail; //will dete tail

        Node *curr = copy.head;
        //transversing through list copying each node and appending it
        while (curr != nullptr){
            append(curr->data);
            curr = curr->next;
            length = copy.length;
        }
    }
    return *this;
}

// Append function which inserts new Nodes into the linked list
void LinkedList::append(Tweet tweet) {

    Node *newNode = new Node; // New allocated node on the heap
    newNode->data = tweet; // transaction object is entered in the data
    newNode->next = nullptr; // next ptr is currently null
    // if head is currently null, the new node will be allocate to the head and tail
    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
    }
        // else new node will follow the current tail
    else {
        this->tail->next = newNode;
        this->tail = newNode;
    }
    *length = *length + 1; // increase length by 1
}

void LinkedList::search(DSString str1, DSString strType) {
    // implement search
    Node *curr = this->head;
    int count = 0; //count is to make sure header isn't printed more than once
    //transversing through list
    while (curr != nullptr) {
        curr = curr->next; //goes to next node
    }
}