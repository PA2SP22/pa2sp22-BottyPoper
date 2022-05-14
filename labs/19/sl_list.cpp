/*
 * Name        : lab_18.cpp
 * Author      : Charles Class
 * Description : Linked List
 */
#include "sl_list.h"
SLList::SLList()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}
SLList::~SLList()
{
    Clear();
}
void SLList::InsertHead(int contents)
{
    if (head_ == NULL)
    {
        head_ = new SLNode(contents);
        tail_ = head_;
    }
    else
    {
        SLNode *temp = new SLNode(contents);
        temp->set_next_node(head_);
        head_ = temp;
    }
    size_++;
}
void SLList::InsertTail(int contents)
{
    if (head_ == NULL)
    {
        InsertHead(contents);
    }
    else
    {
        SLNode *temp = new SLNode(contents);
        tail_->set_next_node(temp);
        tail_ = temp;
        tail_->set_next_node(NULL);
        size_++;
    }
}
void SLList::RemoveHead()
{
    if (size_ > 0)
    {
        SLNode *temp = head_->next_node();
        delete head_;
        head_ = temp;
        size_--;
        if (size_ == 0)
        {
            tail_ = NULL;
        }
    }
}
void SLList::RemoveTail()
{
    if (size_ > 0)
    {
        SLNode *temp = head_;
        if (size_ == 1)
        {
            delete tail_;
            head_=NULL;
            tail_=NULL;
        }
        while (temp->next_node() != tail_)
        {
            temp = temp->next_node();
        }
        delete tail_;
        size_--;
        tail_ = temp;
    }
}
void SLList::Clear()
{
    SLNode *current, *temp;
    current = head_;
    temp = head_;
    for (unsigned int i = 0; i < size_; i++)
    {
        temp = temp->next_node();
        delete current;
        current = temp;
    }
    size_ = 0;
}
int SLList::GetHead() const
{
    if (head_ == NULL)
    {
        return 0;
    }
    else
    {
        return head_->contents();
    }
}
int SLList::GetTail() const
{
    if (head_ == NULL)
    {
        return 0;
    }
    else
    {
        return tail_->contents();
    }
}
unsigned int SLList::size() const
{
    return size_;
}
std::string SLList::ToString() const
{
    std::stringstream output;
    if (size_ != 0)
    {
        SLNode *temp = head_;
        output << head_->contents();
        if (head_->next_node() != NULL)
        {
            temp = head_->next_node();
        }
        for (unsigned int i = 1; i < size_; i++)
        {
            output << ", " << temp->contents();
            if (temp->next_node() != NULL)
            {
                temp = temp->next_node();
            }
        }
    }
    return output.str();
}