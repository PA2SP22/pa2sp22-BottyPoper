#include "todo_item.h"
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