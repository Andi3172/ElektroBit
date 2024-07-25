#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include "Lists.hpp"

using namespace std;


int main(){
    List workList("Work");
    List homeList("Home");

    workList.setTasks({"Task 1", "Task 2", "Task 3"});
    homeList.setTasks({"Task 1", "Task 2", "Task 3"});
    workList.saveToFile();
    homeList.saveToFile();

    workList.loadFromFile();
    homeList.loadFromFile();
    
    cout << "Work List Tasks: \n";
    for(const auto& task: workList.getTasks()){
        cout << "-> " << task << endl;
    }
    cout << "Home List Tasks: \n";
    for(const auto& task: homeList.getTasks()){
        cout << "-> " << task << endl;
    }
    return 0;
}