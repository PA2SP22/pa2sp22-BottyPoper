/*
 * Name        : sl_list.cpp
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
    if (tail_ == NULL)
    {
        tail_ = new SLNode(contents);
        head_ = tail_;
    }
    else
    {
        SLNode *temp = new SLNode(contents);
        tail_->set_next_node(temp);
        tail_ = temp;
    }
    size_++;
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
            head_ = NULL;
            tail_ = NULL;
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
    head_ = NULL;
    tail_ = NULL;
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
void SLList::Insert(int to_insert)
{
    if (size_ == 0)
    {
        InsertHead(to_insert);
    }
    else
    {
        SLNode *behind_temp;
        for (SLNode *temp = head_; temp != NULL; temp = temp->next_node())
        {
            
            if (temp->contents() > to_insert)
            {
                if (temp == head_)
                {
                    InsertHead(to_insert);
                    return;
                }
                else
                {
                    SLNode *to_add = new SLNode(to_insert);
                    behind_temp->set_next_node(to_add);
                    to_add->set_next_node(temp);
                    size_++;
                    return;
                }
            }
            behind_temp=temp;
        }
        // if at end of list
        InsertTail(to_insert);
    }
}
bool SLList::RemoveFirstOccurence(int to_remove)
{
    if (size_ == 0)
    {

        return false;
    }
    else
    {
        SLNode *temp = head_;
        SLNode *behindtemp;
        for (unsigned int i = 0; i < size_; i++)
        {

            if (temp->contents() == to_remove)
            {
                if (temp == head_)
                {
                    RemoveHead();
                }
                else
                {
                    if (temp == tail_)
                    {
                        RemoveTail();
                    }
                    else
                    {
                        behindtemp->set_next_node(temp->next_node());
                        delete temp;
                        size_--;
                    }
                }
                return true;
            }
            behindtemp = temp;
            temp = temp->next_node();
        }

        return false;
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
