// The standards input/output stream library which allows us to use cout and cin
#include <iostream>
// String library - allows us to use the std::string class
#include <string>
// Includes the standard template library (STL) list container (Used to store the todo items)
#include <list>

// Class represents each individual to do list item
class TodoItem {
    private:
    int id;  // Unique identifier for each task
    std::string description; // What the actual task is
    bool completed; // Whether its been completed or not (True or False)

    public:
    TodoItem(): id(0), description(""), completed(false) {} //Default constructor to the items, initialises variables to default values
    ~TodoItem() = default; // Destructor for the class 'TodoItem'

};

int main()
{
    std::cout << "To Do List";
    std::list<TodoItem> todoItems;


    todoItems.clear();
}