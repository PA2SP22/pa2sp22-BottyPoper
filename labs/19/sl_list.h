/*
 * Name        : lab_18.cpp
 * Author      : Charles Class
 * Description : Linked List
 */
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

public:
    SLList();
    ~SLList();
    // make a new list head with specified contents
    void InsertHead(int contents);
    // add a node to the end of the list
    void InsertTail(int contents);
    // remove the head node and set the next
    //   node as the new head.
    void RemoveHead();
    // remove the last node
    void RemoveTail();
    // clear the entire list.
    void Clear();
    // returns the head node
    int GetHead() const;
    // returns the tail node
    int GetTail() const;
    // get the size of the list.
    unsigned int size() const;
    // output list as a string
    std::string ToString() const;
};