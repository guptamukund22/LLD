#include<iostream>
using namespace std;

class IBase{
    public:
        virtual void func() = 0;
};

class ConcreteClass : public IBase{
    public:
        void func() override{
            //overidding the base function
        }
};

class Decorator1 : public IBase{
    private:
        IBase * b;
    public:
        void func() override{
            //adding as a decorator function which will be calling the b func first
        }
};

int main(){
    
    return 0;
}