/*
 * Name        : lab_18.cpp
 * Author      : Charles Class
 * Description : Linked List
 */
#ifndef Doubly_Linked_List
#define Doubly_Linked_List
#include <string>
#include <iostream>
#include <sstream>
#include "dl_node.h"
class DLList
{
private:
    // first node in the Linked List
    DLNode *head_;
    // last node in the linked List
    DLNode *tail_;
    // size of Linked list
    unsigned int size_;

public:
    DLList();
    ~DLList();
    // make a new list head with specified contents
    void PushFront(int contents);
    // add a node to the end of the list
    void PushBack(int contents);
    // remove the head node and set the next
    //   node as the new head.
    void PopFront();
    // remove the last node
    void PopBack();
    // clear the entire list.
    void Clear();
    // returns the head node
    int GetFront() const;
    // returns the tail node
    int GetBack() const;
    // Remove First node of given value
    void RemoveFirst(int);
    // Remove All nodes of a given value
    void RemoveAll(int);
    // find if a value exist on list
    bool Exists(int);
    // get the size of the list.
    unsigned int GetSize() const;
    // output list as a string
    std::string ToStringForwards() const;
    // output list as a string but backwards
    std::string ToStringBackwards() const;
};
#endif