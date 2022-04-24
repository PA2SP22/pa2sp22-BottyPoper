/*
 * Name        : todo_list.cpp
 * Author      : Charles Clarke
 * Description : functions for todo_list class
 */
#include "todo_list.h"
#include <iostream>
#include <sstream>
#include <typeinfo>
using std::endl;
void TodoList::IncreseSize()
{
    std::stringstream testy;
    TodoItem **temp;
    temp = new TodoItem *[list_capacity + 10];
    for (unsigned int i; i < list_capacity;)
    {
        temp[i] = bar[i];
    }
    for (unsigned int i = list_capacity; i < list_capacity + 10; i++)
    {
        temp[i] = NULL;
    }

    list_capacity += 10;
    delete[] bar;
    bar = temp;
}
void TodoList::CompactEmptySpace(unsigned int missing_space)
{
    for (unsigned int i = missing_space; i < list_size; i++)
    {
        bar[i] = bar[i + 1];
    }
}
TodoList::TodoList()
{
    bar = new TodoItem *[25];
    for (unsigned int i = 0; i < 25; i++)
    {
        bar[i] = NULL;
    }

    list_capacity = 25;
    list_size = 0;
}
TodoList::~TodoList()
{
    for (unsigned int i = 0; i < 25; i++)
    {
        delete[] bar[i];
        bar[i] = NULL;
    }
}
void TodoList::AddItem(TodoItem *item_to_add)
{
    if (list_capacity == list_size)
    {
        IncreseSize();
    }
    bar[list_size] = item_to_add;
    list_size += 1;
}
void TodoList::DeleteItem(unsigned int index_to_remove)
{
    index_to_remove -= 1;
    delete bar[index_to_remove];
    bar[index_to_remove] = NULL;
    if (!(index_to_remove == list_size))
    {
        CompactEmptySpace(index_to_remove);
    }
    list_size -= 1;
}
TodoItem *TodoList::GetItem(unsigned int index_to_get)
{
    return bar[index_to_get - 1];
}
void TodoList::Sort()
{
    TodoItem *current = bar[0];
    for (unsigned int i = 1; i < list_size; i++)
    {

       // for (unsigned int j = i - 1; bar[j]->priority()>bar[i]->priority(); j--)
       // {
      //      {
      //         
       //     }
//
        }
    }
    string TodoList::ToFile()
    {
        std::stringstream output;
        for (unsigned int i = 0; i < list_size; i++)
        {
            output << bar[i]->ToFile() << "\n";
        }
        return output.str();
    }
    unsigned int TodoList::GetSize()
    {
        return list_size;
    }
    unsigned int TodoList::GetCapacity()
    {
        return list_capacity;
    }
    std::ostream &operator<<(std::ostream &original, TodoList list_to_output)
    {
        for (unsigned int i = 0; i < list_to_output.GetSize(); i++)
        {
            original << list_to_output.bar[i]->description() << list_to_output.bar[i]->priority()
                     << list_to_output.bar[i]->completed() << std::endl;
        }
        return original;
    }