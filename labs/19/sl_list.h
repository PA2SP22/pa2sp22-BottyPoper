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
    // size of Linked list
    unsigned int size_;

public:
    SLList();
    ~SLList();
    // make a new list head with specified contents
    void InsertHead(int contents);
    // remove the head node and set the next
    //   node as the new head.
    void RemoveHead();
    // clear the entire list.
    void Clear();
    // get the size of the list.
    unsigned int size() const;
    // output list as a string
    std::string ToString() const;
};