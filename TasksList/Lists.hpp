#ifndef LISTS_HPP
#define LISTS_HPP
#include <iostream>
#include <vector>
#include <list>
#include <string>
//save to txt file
#include <fstream>
#include <sstream>
//open from txt file
using namespace std;

class List{
private:
    string name;
    list<string> tasks;
public:
    List(string name) : name(name) {}
    void addTask(string task){
        tasks.push_back(task);
    }
    void removeTask(string task){
        tasks.remove(task);
    }
    void showTasks(){
        cout << "Tasks for: "<< name << ":\n";
        for(const auto& task: tasks){ // access by reference to avoid copying
            cout <<"-> "<< task << endl;
        }
    }

    string getName() const{
        return name;
    }
    void setName(string name){
        this->name = name;
    }

    list<string> getTasks(){
        return tasks;
    }

    void setTasks(list<string> tasks){
        this->tasks = tasks;
    }

    void saveToFile(){
        ofstream file(name + ".txt");
        if(file.is_open()){
            for(const auto& task: tasks){
                file << task << endl;
            }
            file.close();
        }
    }

    void loadFromFile(){
        ifstream file(name + ".txt");
        if(file.is_open()){
            tasks.clear();
            string task;
            while(getline(file, task)){
                tasks.push_back(task);
            }
            file.close();
        }
    }
};

#endif // LISTS_HPP