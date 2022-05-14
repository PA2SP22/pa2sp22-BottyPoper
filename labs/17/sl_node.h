/*
 * Name        : lab_17.h
 * Author      : Charles Class
 * Description : Single Node for Linked list
 */
class SLNode
{
private:
    SLNode* next_node_;
    int contents_;
public:
    SLNode();
    SLNode(int contents);
    ~SLNode();
    // Set the contents for the node
    void set_contents (int contents);
    //Get the Content of the current node
    int contents()const;
    //Set the Next node;
    void set_next_node(SLNode*);
    //get the next node;
    SLNode* next_node() const;
};