#include<iostream>
using namespace std;

class Base{
    public:
        virtual void test(){
            cout<<"This is the base class"<<'\n';
        }
};

class Child : public Base{
    public:

        void test() override{
            cout<<"This is the child class"<<'\n';
        }

        void test2(){
            cout<<"Just checking"<<'\n';
        }
};

int main(){
    Base * b = new Child();
    return 0;
}