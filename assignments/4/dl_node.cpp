/*
 * Name        : dl_node.cpp
 * Author      : Charles Class
 * Description : Single Node for double Linked list
 */
#include "dl_node.h"
DLNode::DLNode()
{
    last_node_ = nullptr;
    next_node_ = nullptr;
    contents_ = 0;
}
DLNode::DLNode(int contents)
{
    last_node_ = nullptr;
    next_node_ = nullptr;
    contents_ = contents;
}
DLNode::~DLNode()
{
}
void DLNode::set_contents(int contents)
{
    contents_ = contents;
}
int DLNode::GetContents() const
{
    return contents_;
}
void DLNode::SetNext(DLNode *next_node)
{
    next_node_ = next_node;
}
void DLNode::SetPrevious(DLNode *last_node)
{
    last_node_ = last_node;
}
DLNode *DLNode::GetNext() const
{
    return next_node_;
}
DLNode *DLNode::GetPrevious() const
{
    return last_node_;
}