#include<iostream>
using namespace std;

class A{
    public:
    friend int f(A* a);        
};

int f(A *a){
    return 5;
}

class B : public A{

};


int main(){
    B * b = new B();
    cout<<f(b);
    return 0;
}