/*
 * Name        : todo_item.cpp
 * Author      : Charles Clarke
 * Description : functions for todo_item class
 */

#include "todo_item.h"

TodoItem::TodoItem(string description, int priority, bool completed) {
  description_ = description;
  priority_ = priority;
  completed_ = completed;
}
TodoItem::TodoItem(string description, int priority) {
  description_ = description;
  priority_ = priority;
  completed_ = false;
}
TodoItem::TodoItem(string description) {
  description_ = description;
  priority_ = 1;
  completed_ = false;
}
string TodoItem::description() {
  return description_;
}
int TodoItem::priority() {
  return priority_;
}
bool TodoItem::completed() {
  return completed_;
}
void TodoItem::set_description(string new_description) {
  description_ = new_description;
}
void TodoItem::set_priority(int new_priority) {
  priority_ = new_priority;
}
void TodoItem::set_completed(bool new_completed) {
  completed_ = new_completed;
}
string TodoItem::ToFile() {
  stringstream output;
  output << description_ << "@" << priority_ << "@" << completed_;
  return Scrub(output.str());
}
string TodoItem::Scrub(string toscrub) {
  for (unsigned int i = 0; i < toscrub.length(); i++) {
    if (toscrub.at(i) == '@') {
      toscrub.at(i) = '`';
    }
  }
  return toscrub;
}
