/*
 * Name        : sl_list.h
 * Author      : Charles Clarke
 * Description : Linked List
 */
#ifndef Linked_List
#define Linked_List
#include <string>
#include <iostream>
#include <sstream>
#include "sl_node.h"
class SLList
{
private:
    // first node in the Linked List
    SLNode *head_;
    // last node in the linked List
    SLNode *tail_;
    // size of Linked list
    unsigned int size_;
    // make a new list head with specified contents
    void InsertHead(int contents);
    // add a node to the end of the list
    void InsertTail(int contents);
    // remove the head node and
    void RemoveHead();
    // remove the last node
    void RemoveTail();
public:
    SLList();
    ~SLList();
    // clear the entire list.
    void Clear();
    // returns the head node
    int GetHead() const;
    // returns the tail node
    int GetTail() const;
    /*
    Creates a new SLNode with the contents of the parameter and
	inserts it into the correct position in the list.
    */
    void Insert(int);
    // Remove First node of given value
    bool RemoveFirstOccurence(int);
    // get the size of the list.
    unsigned int size() const;
    // output list as a string
    std::string ToString() const;
};
#endif