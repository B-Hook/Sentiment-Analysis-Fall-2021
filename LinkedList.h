//
// Created by Braiden Hook on 9/7/21.
//

#ifndef MAIN_CPP_LINKEDLIST_H
#define MAIN_CPP_LINKEDLIST_H

#include"DSString.h"
#include"Tweet.h"

using namespace std;

struct Node {
    Tweet data;
    Node *next;
};

class LinkedList {
public:
    LinkedList(); //constructor
    ~LinkedList(); //destructor
    LinkedList(const LinkedList &copy); //copy constructor
    LinkedList& operator=(const LinkedList &copy); //copy assignment
    void append(Tweet); //append method
    void display(); //searches for transaction and prints it
private: //private data members
    Node *head;
    Node *tail;
    int *length;
};


#endif //MAIN_CPP_LINKEDLIST_H
