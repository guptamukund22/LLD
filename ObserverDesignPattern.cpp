#include<iostream>
#include<vector>
using namespace std;

class IObserver{
    public:
        virtual void update() = 0;
        virtual ~IObserver() = 0;
};  


class IObservable {
    public:
        virtual void addObserver(IObserver * observer)  = 0;
        virtual void removeObserver(IObserver* observer) = 0;
        virtual void notify() = 0;
        virtual ~IObservable() = 0;
};

class concreteObserver : public IObserver{
    private:
        IObservable * observable;
    public:
        concreteObserver(IObservable * observable) : observable(observable){};
        void update(){
            // use the observable to get some value to be updated
        }
};

class concreteObservable : public IObservable{
    private:
        vector<IObserver *> list;
    public:
        //change the virtual functions as per need    
};


int main(){

    return 0;
}