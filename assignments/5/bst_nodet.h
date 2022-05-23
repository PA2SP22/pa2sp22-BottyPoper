/*
 * Name        : bst_nodet.h
 * Author      : Charles Clarke
 * Description : Models information about a single node in the BSTreeT
 */
#ifndef nodetemplate
#define nodetemplate

template <typename T>
class BSTNodeT
{
public:
    BSTNodeT();
    BSTNodeT(T input);
    ~BSTNodeT();
    // Sets the contents to the given parameters value
    void SetContents(T input);
    // Sets the left nodes pointer to the given parameters value
    void SetLeft(BSTNodeT *input);
    // Sets the right nodes pointer to the given parameters value
    void SetRight(BSTNodeT *input);
    // increses the incriment count by 1
    void IncrementCount();
    // Decreses the incriment count by 1
    void DecrementCount();
    // returns the value of contents
    T GetContents() const;
    // retuns the left Node
    BSTNodeT *GetLeft() const;
    BSTNodeT *&GetLeft() ;
    // retuns the right Node
    BSTNodeT *GetRight() const;
    BSTNodeT *&GetRight();
    // return the count
    unsigned int GetCount() const;

private:
    T contents;
    unsigned int amount;
    BSTNodeT *left_;
    BSTNodeT *right_;
};
template <typename T>
BSTNodeT<T>::BSTNodeT()
{
    amount = 0;
    contents = T();
    left_ = NULL;
    right_ = NULL;
}
template <typename T>
BSTNodeT<T>::BSTNodeT(T input)
{
    amount = 0;
    contents = input;
    left_ = NULL;
    right_ = NULL;
}
template <typename T>
BSTNodeT<T>::~BSTNodeT()
{
    left_ = NULL;
    right_ = NULL;
}
template <typename T>
void BSTNodeT<T>::SetContents(T input)
{
    contents = input;
}
template <typename T>
void BSTNodeT<T>::SetLeft(BSTNodeT *input)
{
    left_ = input;
}
template <typename T>
void BSTNodeT<T>::SetRight(BSTNodeT *input)
{
    right_ = input;
}
template <typename T>
void BSTNodeT<T>::IncrementCount()
{
    amount++;
}
template <typename T>
void BSTNodeT<T>::DecrementCount()
{
    amount--;
}
template <typename T>
T BSTNodeT<T>::GetContents() const
{
    return contents;
}
template <typename T>
BSTNodeT<T> *BSTNodeT<T>::GetLeft() const
{
    return left_;
}
template <typename T>
BSTNodeT<T> *&BSTNodeT<T>::GetLeft() 
{
    return left_;
}
template <typename T>
BSTNodeT<T> *BSTNodeT<T>::GetRight() const
{
    return right_;
}
template <typename T>
BSTNodeT<T> *&BSTNodeT<T>::GetRight()
{
    return right_;
}
template <typename T>
unsigned int BSTNodeT<T>::GetCount() const
{
    return amount;
}
#endif