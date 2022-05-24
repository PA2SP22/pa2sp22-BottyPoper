/*
 * Name        : todo_list.h
 * Author      : Charles Clarke
 * Description : Header for todo_list.cpp
 */

#ifndef list_thing
#define list_thing
#include <iostream>
#include "todo_item.h"
class TodoList
{
    // private Data Members:
    TodoItem **bar;
    unsigned int list_capacity;
    unsigned int list_size;
    // Private Member functions
    void IncreseSize();
    void CompactEmptySpace(unsigned int missing_space);

public:
    // Constructor
    TodoList();
    // Destructor
    ~TodoList();
    /*
    AddItem:
    Has one parameter, a dynamic instance of
    TodoItem (i.e. TodoItem*). If there is room in the array add the new
    dynamic instance to the first available spot (i.e. the current size). If
    the array is full, increase capacity by 10 and then add the item.
    */
    void AddItem(TodoItem *item_to_add);
    /*
    DeleteItem:
    as one parameter, an integer of the location
    to delete. Please note the location is in human-readable form, i.e.
    location 1 is really array index 0. After you delete the item you will
    need to pack your array (shift all items "down" so there are no
    empty slots between items).
    */
    void DeleteItem(unsigned int index_to_remove);
    /*
    GetItem:
    Has one parameter, an integer of the location to
    retrieve the TodoItem. Please note the location is in human-
    readable form, i.e. location 1 is really array index 0. This function
    will return a pointer to the TodoItem requested. If that location
    doesn't exist it returns NULL.
    */
    TodoItem *GetItem(unsigned int index_to_get);
    /*
    Sort:
    Sorts the array by the priorities of the items. (1 is
    highest priority, 5 is lowest).
    */
    void Sort();
    /*
    ToFile:
    Named ToFile. Returns a string containing all TodoItems in the list.
    Uses the TodoItems ToFile function to create. Each item should be
    on its own line.
    */
    string ToFile();
    // Accessors:
    unsigned int GetSize();
    unsigned int GetCapacity();
    // friend
    friend std::ostream& operator<<(std::ostream &original,TodoList &list_to_output);
};
#endif