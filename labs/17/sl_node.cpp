/*
 * Name        : lab_17.cpp
 * Author      : Charles Class
 * Description : Single Node for Linked List
 */
#include "sl_node.h"
SLNode::SLNode()
{
    next_node_ = nullptr;
    contents_=0;
}
SLNode::SLNode(int contents)
{
    next_node_ = nullptr;
    contents_ = contents;
}
SLNode::~SLNode()
{
}
void SLNode::set_contents(int contents)
{
    contents_=contents;
}
int SLNode::contents() const
{
    return contents_;
}
void SLNode::set_next_node(SLNode * next_node)
{
    next_node_=next_node;
}
SLNode *SLNode::next_node() const
{
    return next_node_;
}