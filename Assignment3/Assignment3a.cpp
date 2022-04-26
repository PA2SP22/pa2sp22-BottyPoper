#include <string>
#include <iostream>
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
int main(){
    TodoItem shit("rape the cat",1,0);
    cout << shit.ToFile();
    return  0;
}
TodoItem::TodoItem(string description, int priority, bool completed){
    description_=description;
    priority_=priority;
    completed_=completed;
}
string TodoItem::GetDescription(){
   return  description_;
}
int TodoItem::GetPriority(){
    return priority_;
}
bool TodoItem::GetCompleted(){
    return completed_;
}
void TodoItem::EditDescription(string new_description){
    description_=new_description;
}
void TodoItem::EditPriority(int new_priority){
    priority_=new_priority;
}
void TodoItem::EditCompleted(bool new_completed){
    completed_=new_completed;
}
string TodoItem::ToFile(){
stringstream output;
output << description_ << "@" << priority_ << "@" << completed_;
return Scrub(output.str());
}
string TodoItem::Scrub(string toscrub){
for(unsigned int i = 0; i<toscrub.length();i++){
  if(toscrub.at(i)=='@'){
      toscrub.at(i)='`';
  }  
}
return toscrub;
}