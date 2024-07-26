#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include "Lists.hpp"
#include "TaskManager.hpp"

using namespace std;

void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Show tasks\n";
    cout << "2. Add task\n";
    cout << "3.Exit\n";
    cout << "4. Return to List selection\n";
    cout << "Enter your choice: ";
}

int main()
{
    bool exit = false;

    TaskManager taskManager;
    taskManager.addList("Work");
    taskManager.addList("Home");
    taskManager.addList("School");

    while (!exit)
    {
        taskManager.showLists();

        string listName;
        cout << "Enter list name: ";
        cin >> listName;

        List *selectedList = nullptr;
        for (auto &list : taskManager.getLists())
        {
            if (list.getName() == listName)
            {
                selectedList = &list;
                break;
            }
        }

        if (selectedList == nullptr)
        {
            cout << "List not found\n";
            return 1;
        }

        int choice;
        bool returnToList = false;
        do
        {
            displayMenu();
            cin >> choice;
            switch (choice)
            {
            case 1:
                selectedList->showTasks();
                break;
            case 2:
            {
                string task;
                cout << "Enter new task: ";
                cin.ignore();
                getline(cin, task);
                selectedList->saveNewTaskToFile(task);
                break;
            }
            case 3:
                cout << "Finished\n";
                exit = true;
                break;

            case 4:
                returnToList = true;
                break;
            default:
                cout << "Invalid choice\n";
            }
        } while (!returnToList && !exit);
    }

    return 0;
}