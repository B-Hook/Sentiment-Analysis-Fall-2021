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
    newNode->data = tweet; // tweet object is entered in the data
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

/*void LinkedList::remove(DSString word) {
    Node* temp = this->head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data.getWord() == word) {
        this->head = temp->next;
        delete temp;
        return;
    }
    else {
        while (temp != nullptr && temp->data.getWord() != word) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return;

        prev->next = temp->next;

        delete temp;
    }
}*/
void LinkedList::display() {
    // implement search
    Node *curr = this->head;
    //transversing through list
    while (curr != nullptr) {
        //cout << curr->data.getSVal().c_str() << " : ";

        //for (int i = 0; i < curr->data.getActualTweet().size(); i++) {
            //cout << curr->data.getActualTweet().at(i).c_str() << " ";
        //}
        cout << "( " << curr->data.getWord().c_str() << " : " << curr->data.getCount() << " )" << endl;
        curr = curr->next; //goes to next node
    }
}

bool LinkedList::search(DSString &word) {
    Node *curr = this->head;
    //transversing through list
    while (curr != nullptr) {
        if(word == curr->data.getWord()) {
            int count = curr->data.getCount() + 1; //adds 1 to the existing count for the word
            curr->data.setCount(count);
            return true;
        }
        //cout << endl;
        curr = curr->next;
    }

        return false;
}

int LinkedList::getSize() {
    int count = 0;
    Node *curr = this->head;
    //transversing through list
    while (curr != nullptr) {

        count++;

        curr = curr->next;
    }

    return count;
}

/*void LinkedList::remove1(LinkedList &positive) {

    Node *negCurr = this->head;
    //Node *negPrev = negCurr;
    //Node *posCurr = positive.head;
    //transversing through list
    while (negCurr != nullptr) {
        Node *posCurr = positive.head;
        //Node *posPrev = posCurr;
        while (posCurr != nullptr){
            if (negCurr->data.getWord() == posCurr->data.getWord()){
                if (negCurr->data.getCount() > posCurr->data.getCount() + 50){
                    positive.remove(posCurr->data.getWord());
                }
                if (posCurr->data.getCount() > negCurr->data.getCount() + 50){
                    this->remove(negCurr->data.getWord());
                }
                else{
                    positive.remove(posCurr->data.getWord());
                    this->remove(negCurr->data.getWord());
                }
                //break;
            }
            //posPrev = posCurr;
            posCurr = posCurr->next;
        }
        //negPrev = negCurr;
        negCurr = negCurr->next;
    }
}*/
