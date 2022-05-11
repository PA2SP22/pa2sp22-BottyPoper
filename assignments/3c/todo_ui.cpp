/*
 * Name        : todo_ui.cpp
 * Author      : Charles Clarke
 * Description : A minimalist Todo 
 */
#include "todo_ui.h"
int main()
{
    TodoUI now;
    now.Menu();
    return 1;
}
TodoUI::TodoUI()
{
    data = new TodoList;
}
TodoUI::~TodoUI()
{
    delete data;
    data = NULL;
}
void TodoUI::Menu()
{
    bool exit = false;
    while (!exit)
    {
        cout << "\nWelcome to TodoList UI Tool\n"
             << "Select the corispoinding Number for your desired option\n"
             << "\"1\" Create new item\n"
             << "\"2\" Edit an existing item\n"
             << "\"3\" View all List Items\n"
             << "\"4\" View a specific item\n"
             << "\"5\" Delete all item\n"
             << "\"6\" Delete a specific item\n"
             << "\"7\" Quit\n";
        int coice = read.readInt();
        switch (coice)
        {
        case 1:
            NewItem();
            break;
        case 2:
            EditItem();
            break;
        case 3:
            ViewIteams();
            break;
        case 4:
            ViewSpecifiedIteam();
            break;
        case 5:
            DeleteAll();
            break;
        case 6:
            DeleteItem();
            break;
        case 7:
            cout << "Computer Run Script \"Suicide()\";";
            cin.get();
            exit = true;
            break;
        default:
            cout << "invalid Input, You degenerate\n";
            cin.get();
            break;
        }
    }
}
void TodoUI::NewItem()
{
    cout << "New Item\n"
         << "Input desired description\n";
    string description = read.readString();
    cout << " Now enter desired priority\n";
    int priority = read.readInt();
    cout << "Now enter desired completness";
    bool completed = read.readBool();
    data->AddItem(new TodoItem(description, priority, completed));
}
void TodoUI::EditItem()
{
    cout << "Edit Item\n"
         << *data << endl
         << "select item to edit by entering the corresponding value";
    int item_to_edit = read.readInt();
    cout << data->GetItem(item_to_edit)->ToFile();
    cin.get();
    cout << "Enter desired description\n";
    string description = read.readString();
    cout << "now enter desired priority\n";
    int priority = read.readInt();
    cout << "now enter if the task is completed\n";
    bool completed = read.readBool();
    data->GetItem(item_to_edit)->set_description(description);
    data->GetItem(item_to_edit)->set_priority(priority);
    data->GetItem(item_to_edit)->set_completed(completed);
}
void TodoUI::DeleteItem()
{
    cout << "Delete One Item\n"
         << *data
         << "Select Iteam to delete by entering corrisponding value";
    int item_to_delete = read.readInt();
    cout << data->GetItem(item_to_delete)->ToFile() << "was selected";
    cin.get();
    data->DeleteItem(item_to_delete);
}
void TodoUI::ViewIteams()
{
    cout << data->ToFile();
    cin.get();
}
void TodoUI::ViewSpecifiedIteam()
{
    cout << "view Specific Item"
         <<data
         << "select iteam to view";
cout << data->GetItem(read.readInt()) << " View The Item in all its glory";
}
void TodoUI::DeleteAll()
{
    delete data;
    data = new TodoList;
}
