#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Lists.hpp"
#include <vector>

using namespace std;

class TaskManager
{
private:
    vector<List> lists;

public:
    void addList(string name){
        lists.push_back(List(name));
    }
    void removeList(string name){
        for(auto i = lists.begin(); i != lists.end(); i++){
            if(i->getName() == name){
                lists.erase(i);
                break;
            }
        }
    }

    void showLists(){
        cout << "Lists:\n";
        for(const auto& list: lists){
            cout << "-> "<< list.getName() <<endl;
        }
    }

    List* getList(string name){
        for(auto& list: lists){
            if(list.getName()== name){
                return &list;
            }
        }
        return nullptr;
    }

};