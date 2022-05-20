/*
 * Name        : lab_18.cpp
 * Author      : Charles Class
 * Description : Linked List
 */
#include "dl_list.h"
DLList::DLList()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}
DLList::~DLList()
{
    Clear();
}
void DLList::PushFront(int contents)
{
    if (head_ == NULL)
    {
        head_ = new DLNode(contents);
        tail_ = head_;
    }
    else
    {
        DLNode *temp = new DLNode(contents);
        temp->SetNext(head_);
        head_->SetPrevious(temp);
        head_ = temp;
    }
    size_++;
}
void DLList::PushBack(int contents)
{
    if (tail_ == NULL)
    {
        tail_ = new DLNode(contents);
        head_ = tail_;
    }
    else
    {
        DLNode *temp = new DLNode(contents);
        temp->SetPrevious(tail_);
        tail_->SetNext(temp);
        tail_ = temp;
    }
    size_++;
}
void DLList::PopFront()
{
    if (size_ > 0)
    {
        DLNode *temp = head_->GetNext();
        delete head_;
        head_ = temp;
        size_--;
        if (size_ == 0)
        {
            tail_ = NULL;
        }
        else
        {
            temp->SetPrevious(NULL);
        }
    }
    else
    {
        std::cerr << "List Empty";
    }
}
void DLList::PopBack()
{
    if (size_ > 0)
    {
        DLNode *temp = tail_->GetPrevious();
        delete tail_;
        tail_ = temp;
        size_--;
        if (size_ == 0)
        {
            head_ = NULL;
        }
        else
        {
            temp->SetNext(NULL);
        }
    }
    else
    {
        std::cerr << "List Empty";
    }
}
void DLList::Clear()
{
    DLNode *current, *temp;
    current = head_;
    temp = head_;
    for (unsigned int i = 0; i < size_; i++)
    {
        temp = temp->GetNext();
        delete current;
        current = temp;
    }
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}
int DLList::GetFront() const
{
    if (head_ == NULL)
    {
        std::cerr << "List Empty";
        return 0;
    }
    else
    {
        return head_->GetContents();
    }
}
int DLList::GetBack() const
{
    if (head_ == NULL)
    {
        std::cerr << "List Empty";
        return 0;
    }
    else
    {
        return tail_->GetContents();
    }
}
void DLList::RemoveFirst(int to_remove)
{
    if (size_ == 0)
    {
        std::cerr << "Not Found";
        return;
    }
    else
    {
        DLNode *temp = head_;
        for (unsigned int i = 0; i < size_; i++)
        {

            if (temp->GetContents() == to_remove)
            {
                if (temp == head_)
                {
                    PopFront();
                }
                else
                {
                    if (temp == tail_)
                    {
                        PopBack();
                    }
                    else
                    {
                        temp->GetPrevious()->SetNext(temp->GetNext());
                        temp->GetNext()->SetPrevious(temp->GetPrevious());
                        delete temp;
                        size_--;
                    }
                }
                return;
            }
            temp = temp->GetNext();
        }
        std::cerr << "Not Found";
    }
}
void DLList::RemoveAll(int to_remove)
{
    if (!Exists(to_remove))
    {
        std::cerr << "Not Found";
        return;
    }
    while (true)
    {
        if (Exists(to_remove))
        {
            RemoveFirst(to_remove);
        }
        else
        {
            return;
        }
    }
}
bool DLList::Exists(int to_find)
{
    DLNode *temp = head_;
    for (unsigned int i = 0; i < size_; i++)
    {
        if (temp->GetContents() == to_find)
        {
            return true;
        }
        temp = temp->GetNext();
    }
    return false;
}
unsigned int DLList::GetSize() const
{
    return size_;
}
std::string DLList::ToStringForwards() const
{
    std::stringstream output;
    if (size_ != 0)
    {
        DLNode *temp = head_;
        output << head_->GetContents();
        if (head_->GetNext() != NULL)
        {
            temp = head_->GetNext();
        }
        for (unsigned int i = 1; i < size_; i++)
        {
            output << ", " << temp->GetContents();
            if (temp->GetNext() != NULL)
            {
                temp = temp->GetNext();
            }
        }
    }
    else
    {
        std::cerr << "List Empty";
    }
    return output.str();
}
std::string DLList::ToStringBackwards() const
{
    std::stringstream output;
    if (size_ != 0)
    {
        DLNode *temp = tail_;
        output << tail_->GetContents();
        if (tail_->GetPrevious() != NULL)
        {
            temp = tail_->GetPrevious();
        }
        for (unsigned int i = 1; i < size_; i++)
        {
            output << ", " << temp->GetContents();
            if (temp->GetPrevious() != NULL)
            {
                temp = temp->GetPrevious();
            }
        }
    }
    else
    {
        std::cerr << "List Empty";
    }
    return output.str();
}
