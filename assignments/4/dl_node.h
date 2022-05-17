/*
 * Name        : dl_node.h
 * Author      : Charles Class
 * Description : Single Node for double Linked list
 */
#ifndef single_node_for_dl_list
#define single_node_for_dl_list
class DLNode
{
private:
    DLNode* last_node_;
    DLNode* next_node_;
    int contents_;
public:
    DLNode();
    DLNode(int contents);
    ~DLNode();
    // Set the contents for the node
    void set_contents (int);
    //Get the Content of the current node
    int GetContents()const;
    //Set the Next node;
    void SetNext(DLNode*);
    //set the last node;
    void SetPrevious(DLNode*);
    //get the next node;
    DLNode* GetNext() const;
    //get last node
    DLNode* GetPrevious() const;

};
#endif