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
    ~TodoItem() = default;                                   // Destructor for the class 'TodoItem'

    bool create(std::string new_description)
    {
        // Generates random integer between 1 and 100
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; }
    void setCompleted(bool val) { completed = val; }
};

int main()
{
    int input_option;
    int input_id;
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;

    srand(time(NULL));

    todoItems.clear();

    TodoItem test;
    test.create("this is a test");
    todoItems.push_back(test);

    while (1)
    {
        system("clear");
        std::cout << "To Do List";
        std::cout << std::endl
                  << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++)
        {

            std::string completed = it->isCompleted() ? "done" : "not done";

            std::cout << it->getId() << " | " << it->getDescription() << " | "
                      << completed << std::endl;
        }

        if (todoItems.empty())
        {
            std::cout << "Add your tasks" << std::endl;
        }

        std::cout << "[1] Add a Task | ";
        std::cout << "[2] Mark a task as completed | ";
        std::cout << "[3] Quit | " << std::endl;

        std::cout << "I want to: ";

        std::cin >> input_option;

        if (input_option == 3)
        {
            std::cout << "Bye!" << std::endl;
            break;
        }
        else if (input_option == 2)
        {
            std::cout << "Enter the ID value you want to mark as complete";
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++)
            {
                if (input_id == it->getId())
                {
                    it->setCompleted(true);
                    break;
                }
            }
        }
        else if (input_option == 1)
        {
        }
    }
    return 0;
}
