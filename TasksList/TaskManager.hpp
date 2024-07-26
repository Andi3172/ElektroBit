#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include "Lists.hpp"

using namespace std;

class TaskManager {
private:
    vector<string> listNames;
    vector<List> lists;
public:
    TaskManager() = default;

    void addList(string name){
        List newList(name);
        newList.loadFromFile();
        listNames.push_back(name);
        lists.push_back(newList);
    }

    void removeList(string name){
        auto it = find(listNames.begin(), listNames.end(), name);
        if(it != listNames.end()){
            lists.erase(lists.begin() + distance(listNames.begin(), it));
            listNames.erase(it);
        }
    }

    void showLists(){
        cout << "Lists: \n";
        for(const auto& list: listNames){
            cout << "-> " << list << endl;
        }
    }

    vector<List>& getLists(){
        return lists;
    }



};

#endif //TASKMANAGER_HPP