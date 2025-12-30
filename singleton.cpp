#include<iostream>
#include<pthread.h>
using namespace std;

class Singleton{
    private:
        static Singleton * instance;
        static pthread_mutex_t lock;
        Singleton(){
            // logic for instantiation 
        };

    public:
        static Singleton * getInstance(){
            if(instance==nullptr){
                pthread_mutex_lock(&lock);
                if(instance==nullptr){
                    instance = new Singleton();
                }
                pthread_mutex_unlock(&lock);
            }
            return instance;
        }
};

Singleton * Singleton::instance = nullptr;
pthread_mutex_t Singleton::lock = PTHREAD_MUTEX_INITIALIZER;

int main(){

    Singleton * a = Singleton::getInstance();
    Singleton * b = Singleton::getInstance();

    return 0;
}