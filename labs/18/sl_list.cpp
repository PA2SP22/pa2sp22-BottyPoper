#include "sl_list.h"
SLList::SLList()
{
    head_ = NULL;
    size_ = 0;
}
SLList::~SLList()
{
}
void SLList::InsertHead(int contents)
{
    if (head_ == NULL)
    {
        head_ = new SLNode(contents);
    }
    else
    {
        SLNode *temp = new SLNode(contents);
        temp->set_next_node(head_);
        head_ = temp;
    }
    size_++;
}
void SLList::RemoveHead()
{
    if (size_>0)
    {
        SLNode *temp = head_->next_node();
        delete head_;
        head_ = temp;
        size_--;
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
unsigned int SLList::size() const
{
    return size_;
}
std::string SLList::ToString() const
{
    std::stringstream output;
    std::cout<<size_<<std::endl;
    if (size_ != 0)
    {
        SLNode *temp = head_;
        output << head_->contents();
        if (head_->next_node() != NULL)
        {
            temp=head_->next_node();
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