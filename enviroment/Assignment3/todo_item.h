#include <string>
#include <sstream>
using namespace std;
class TodoItem{
    //Private Variables
        string description_;
        int priority_;
        bool completed_;
    //Private Member Function
        string Scrub(string toscrub);
    public:
    //Constructor:
    TodoItem(string description, int priority, bool completed);
    //Accessors:
    string GetDescription();
    int GetPriority();
    bool GetCompleted();
    //Mutators:
    void EditDescription(string new_description);
    void EditPriority(int new_priority);
    void EditCompleted(bool new_completed);
    //Member Function
    string ToFile();
    
};