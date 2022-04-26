/*
 * Name        : todo_item.h
 * Author      : Charles Clarke
 * Description : header for todo_item
 */

#include <string>

#include <sstream>

using std::string;
// using std::sstream;
class TodoItem
{
  // Private Variables
  string description_;
  int priority_;
  bool completed_;
  // Private Member Function
  string Scrub(string toscrub);

public:
  // Constructor:
  TodoItem(string description, int priority, bool completed);
  TodoItem(string description, int priority);
  TodoItem(string description);
  // Accessors:
  string description();
  int priority();
  bool completed();
  // Mutators:
  void set_description(string new_description);
  void set_priority(int new_priority);
  void set_completed(bool new_completed);
  // Member Function
  /*
   *ToFile Returns a string containing the description,
   *priority, and completed status, separated by the @ symbol (This is
   *the description@3@1). Uses the scrub function to change @
   *symbols that may be contained in description_.
   */
  string ToFile();
};