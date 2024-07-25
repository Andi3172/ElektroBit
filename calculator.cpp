#include <iostream>
using namespace std;

class Calculator{
    private:
    char operation;
    int a, b;
    
    public:
    int add(int a, int b){
        return a+b;
    }
    int substract(int a, int b){
        return a-b;
    }
    int multiply(int a, int b){
        return a*b;
    }
    int divide(int a, int b){
        return a/b;
    }

    void setOperation(char operation){
        this->operation = operation;
    }
    void setA(int a){
        this->a = a;
    }
    void setB(int b){
        this->b = b;
    }
    char getOperation(){
        return operation;
    }
    int getA(){
        return a;
    }
    int getB(){
        return b;
    }
    void calculate(){
        switch(operation){
            case '+':
                cout << add(a,b)<<"\n";
                break;
            case '-':
                cout << substract(a,b)<<"\n";
                break;
            case '*':
                cout << multiply(a,b)<<"\n";
                break;
            case '/':
                cout << divide(a,b)<<"\n";
                break;
            default:
                cout << "Invalid operation\n";
                break;
    
        }
    }
};

int main(){
    Calculator Calculator;
    char operation;
    int a, b;
    cout << "Enter first number: ";
    cin>>a;
    cout << "\nEnter second number: ";
    cin>>b;
    cout << "Enter operation: ";
    cin>>operation;
    Calculator.setA(a);
    Calculator.setB(b);
    Calculator.setOperation(operation);

    Calculator.calculate();
    return 0;
}



