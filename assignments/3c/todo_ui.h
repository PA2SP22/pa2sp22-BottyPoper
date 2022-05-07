#include "todo_list.h"
#include "CinReader.h"
#include "todo_item.h"
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