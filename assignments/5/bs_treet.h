/*
 * Name        : bs_treet.h
 * Author      : Charles Clarke
 * Description : FBSTreeTirst Lab of the Year
 */
#ifndef treetemplate
#define treetemplate

#include <string>
#include <sstream>
#include "bst_nodet.h"
template <typename T>
class BSTreeT
{
public:
    BSTreeT();
    ~BSTreeT();
    // returns the amount of nodes on the tree
    unsigned int GetSize();
    // destroys the tree
    void Clear();
    // insert value of parameters given value
    int Insert(T input);
    // returns true if a value exist
    bool Exists(T input);
    // I dont understand
    int Remove(T input);
    // returns the pointer to a node of the parameters given value
    BSTNodeT<T> *Get(T input);
    // returns a string of all nodes in tree(whatever that means)
    std::string ToStringForwards() const;
    // returns a string of all nodes in tree in order(whatever that means)but the other way
    std::string ToStringBackwards() const;

private:
    // the root node for the tree
    BSTNodeT<T> *root_;
    // how many nodes exist within the tree
    unsigned int size_;
    // Helper Funcion for Get
    BSTNodeT<T> *Get(T input, BSTNodeT<T> *&) const;
    BSTNodeT<T> *&Get(T input, BSTNodeT<T> *&);
    // Helper Funcion for Remove
    int Remove(T input, BSTNodeT<T> *&);
    // Helper Funcion for Exists
    bool Exists(T input, BSTNodeT<T> *&);
    // Helper Funcion for Insert
    int Insert(T input, BSTNodeT<T> *&);
    // helper Function for Clear
    void Clear(BSTNodeT<T> *&);
    // helper function for TOStringForwards
    std::string ToStringForwards(BSTNodeT<T> *) const;
    // helper function for TOStringBackwards
    std::string ToStringBackwards(BSTNodeT<T> *) const;
    // get min
    BSTNodeT<T> *Min(BSTNodeT<T> *&) const;
    BSTNodeT<T> *&Min(BSTNodeT<T> *&);
};
template <typename T>
BSTreeT<T>::BSTreeT()
{
    root_ = NULL;
    size_ = 0;
}
template <typename T>
BSTreeT<T>::~BSTreeT()
{
    Clear();
}
template <typename T>
unsigned int BSTreeT<T>::GetSize()
{
    return size_;
}
template <typename T>
void BSTreeT<T>::Clear()
{
    Clear(root_);
}
template <typename T>
void BSTreeT<T>::Clear(BSTNodeT<T> *&target_node)
{
    if (target_node != NULL)
    {
        if (target_node->GetLeft() != NULL)
        {
            Clear(target_node->GetLeft());
        }
        if (target_node->GetRight() != NULL)
        {
            Clear(target_node->GetRight());
        }
        delete target_node;
        target_node = NULL;
        size_ = 0;
    }
}
template <typename T>
int BSTreeT<T>::Insert(T input)
{
    return Insert(input, root_);
}
template <typename T>
int BSTreeT<T>::Insert(T input, BSTNodeT<T> *&target_node)
{
    if (target_node != NULL)
    {
        if (input < target_node->GetContents())
        {
            return Insert(input, target_node->GetLeft());
        }
        else if (input > target_node->GetContents())
        {
            return Insert(input, target_node->GetRight());
        }
        else
        {
            target_node->IncrementCount();
            return target_node->GetCount();
        }
    }
    else
    {
        target_node = new BSTNodeT<T>(input);
        size_++;
        target_node->IncrementCount();
        return target_node->GetCount();
    }
}
template <typename T>
bool BSTreeT<T>::Exists(T input)
{
    if (root_ != NULL)
    {
        return Exists(input, root_);
    }
    return false;
}
template <typename T>
bool BSTreeT<T>::Exists(T input, BSTNodeT<T> *&target_node)
{
    if (input < target_node->GetContents())
    {
        if (target_node->GetLeft() != NULL)
        {
            return Exists(input, target_node->GetLeft());
        }
        else
        {
            return false;
        }
    }
    else if (input > target_node->GetContents())
    {
        if (target_node->GetRight() != NULL)
        {
            return Exists(input, target_node->GetRight());
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}
template <typename T>
int BSTreeT<T>::Remove(T input)
{
    if (Exists(input))
    {
        return Remove(input, Get(input, root_));
    }
    else
    {
        return -1;
    }
}
template <typename T>
int BSTreeT<T>::Remove(T input, BSTNodeT<T> *&target_node)
{
    if (target_node->GetLeft() != NULL && target_node->GetRight() != NULL)
    {
        if (target_node->GetCount() == 1)
        {
            BSTNodeT<T> *temp = Min(target_node->GetRight());
            target_node->SetContents(temp->GetContents());
            while (Remove(input) > 0)
            {
                target_node->IncrementCount();
            }
            target_node->DecrementCount();
            size_--;
            return 0;
        }
        else
        {
            target_node->DecrementCount();
            return target_node->GetCount();
        }
    }
    else if (target_node->GetLeft() != NULL)
    {
        if (target_node->GetCount() == 1)
        {
            BSTNodeT<T> *temp = target_node->GetLeft();
            delete target_node;
            target_node = temp;
            size_--;
            return 0;
        }
        else
        {
            target_node->DecrementCount();
            return target_node->GetCount();
        }
    }
    else if (target_node->GetRight() != NULL)
    {
        if (target_node->GetCount() == 1)
        {
            BSTNodeT<T> *temp = target_node->GetRight();
            delete target_node;
            target_node = temp;
            size_--;
            return 0;
        }
        else
        {
            target_node->DecrementCount();
            return target_node->GetCount();
        }
    }
    else // (target_node->GetLeft() = NULL && target_node->GetRight() = NULL)
    {
        if (target_node->GetCount() == 1)
        {
            // remove node
            delete target_node;
            target_node = NULL;
            size_--;
            return 0;
        }
        else
        {
            target_node->DecrementCount();
            return target_node->GetCount();
        }
    }
}
template <typename T>
BSTNodeT<T> *BSTreeT<T>::Get(T input)
{
    if (Exists(input))
    {
        return Get(input, root_);
    }
    else
    {
        return NULL;
    }
}
template <typename T>
BSTNodeT<T> *BSTreeT<T>::Get(T input, BSTNodeT<T> *&target_node) const
{
    if (input < target_node->GetContents())
    {
        return Get(input, target_node->GetLeft());
    }
    else if (input > target_node->GetContents())
    {
        return Get(input, target_node->GetRight());
    }
    else
    {
        return target_node;
    }
}
template <typename T>
BSTNodeT<T> *&BSTreeT<T>::Get(T input, BSTNodeT<T> *&target_node)
{
    if (input < target_node->GetContents())
    {
        return Get(input, target_node->GetLeft());
    }
    else if (input > target_node->GetContents())
    {
        return Get(input, target_node->GetRight());
    }
    else
    {
        return target_node;
    }
}
template <typename T>
std::string BSTreeT<T>::ToStringForwards() const
{
    std::string output;
    if (root_ != NULL)
    {
        output = ToStringForwards(root_);
    }
    return output;
}
template <typename T>
std::string BSTreeT<T>::ToStringForwards(BSTNodeT<T> *target_node) const
{
    std::stringstream output;
    if (target_node->GetLeft() != NULL)
    {
        output << ToStringForwards(target_node->GetLeft()) << ", ";
    }
    output << target_node->GetContents();
    if (target_node->GetRight() != NULL)
    {
        output << ", " << ToStringForwards(target_node->GetRight());
    }
    return output.str();
}
template <typename T>
std::string BSTreeT<T>::ToStringBackwards() const
{
    std::string output;
    if (root_ != NULL)
    {
        output = ToStringBackwards(root_);
    }
    return output;
}
template <typename T>
std::string BSTreeT<T>::ToStringBackwards(BSTNodeT<T> *target_node) const
{
    std::stringstream output;
    if (target_node->GetRight() != NULL)
    {
        output << ToStringBackwards(target_node->GetRight()) << ", ";
    }
    output << target_node->GetContents();
    if (target_node->GetLeft() != NULL)
    {
        output << ", " << ToStringBackwards(target_node->GetLeft());
    }

    return output.str();
}
template <typename T>
BSTNodeT<T> *BSTreeT<T>::Min(BSTNodeT<T> *&target_node) const
{
    if (target_node->GetLeft() != NULL)
    {
        return Min(target_node->GetLeft());
    }
    else
    {
        return target_node;
    }
}
template <typename T>
BSTNodeT<T> *&BSTreeT<T>::Min(BSTNodeT<T> *&target_node)
{
    if (target_node->GetLeft() != NULL)
    {
        return Min(target_node->GetLeft());
    }
    else
    {
        return target_node;
    }
}
#endif
