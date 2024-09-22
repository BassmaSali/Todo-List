// The standards input/output stream library which allows us to use cout and cin
#include <iostream>
// String library - allows us to use the std::string class
#include <string>
// Includes the standard template library (STL) list container (Used to store the todo items)
#include <list>
#include <ctime>

// Class represents each individual to do list item
class TodoItem
{
private:
    int id;                  // Unique identifier for each task
    std::string description; // What the actual task is
    bool completed;          // Whether its been completed or not (True or False)

public:
    TodoItem() : id(0), description(""), completed(false) {} // Default constructor to the items, initialises variables to default values
    ~TodoItem() = default;  // Destructor for the class 'TodoItem'

    bool create(std::string new_description) {
        // Generates random integer between 1 and 100
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }
    
    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; }
                                     
};

int main()
{
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;

    srand(time(NULL));

    todoItems.clear();

    while(1) {
        system("cls");
        std::cout << "To Do List";
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {
            std::cout << it->getId() << " | " << it->getDescription() << " | "
                << it->isCompleted() << std::endl;
        }
    }


}