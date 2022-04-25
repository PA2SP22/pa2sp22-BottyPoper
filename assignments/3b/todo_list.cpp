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
    TodoItem **temp;
    temp = new TodoItem *[list_capacity + 10];
    for (unsigned int i = 0; i < list_capacity; i++)
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

    int j;
    TodoItem *current;
    for (unsigned int i = 1; i < list_size; i++)
    {
        current = new TodoItem(bar[i]->description(), bar[i]->priority(), bar[i]->completed());
        
        j = i;;
        while (current->priority() < bar[j - 1]->priority() && j > 0)
        {
            std::cout <<"j " << j << " bar[j] " << bar[j]->ToFile() << " bar[j-1] "<< bar[j-1]->ToFile()<< endl;
            bar[j] = bar[j - 1];
            std::cout <<"how?" << endl;
            j--;
        }
        bar[j] = current;
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
std::ostream &operator<<(std::ostream &original, TodoList &list_to_output)
{
    for (unsigned int i = 0; i < list_to_output.GetSize(); i++)
    {
        original << list_to_output.bar[i]->description() << list_to_output.bar[i]->priority()
                 << list_to_output.bar[i]->completed() << std::endl;
    }
    return original;
}