/*
 * Name        : todo_item.h
 * Author      : Charles Clarke
 * Description : functions for todo_item class
 */

#include "todo_list.h"
#include "CinReader.h"
#include "todo_item.h"
// Todo UI is a minimalist terminal ui tool.
class TodoUI
{
private:
    CinReader read;
    TodoList *data;
    void NewItem();
    void EditItem();
    void DeleteItem();
    void ViewIteams();
    void ViewSpecifiedIteam();
    void DeleteAll();
public:
    TodoUI();
    ~TodoUI();
    void Menu();
};