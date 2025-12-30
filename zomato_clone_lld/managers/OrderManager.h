#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include<iostream>
#include<vector>
#include<pthread.h>
#include "../model/Order.h"
using namespace std;

class OrderManager{
    private:
        static OrderManager* instance;
        static pthread_mutex_t lock;
        vector<Order *> orders;
        OrderManager(){

        }
    public:
        static OrderManager * getInstance(){
            if(!instance){
                pthread_mutex_lock(&lock);
                if(instance==nullptr) instance = new OrderManager();
                pthread_mutex_unlock(&lock);
            }
            return instance;
        } 

        void addOrder(Order * order){
            orders.push_back(order);
        }

        void listOrders() {
        cout << "\n--- All Orders ---" << endl;
        for (auto order : orders) {
            cout << order->getType() << " order for " << order->getUser()->getName()
                    << " | Total: ₹" << order->getTotal()
                    << " | At: " << order->getScheduled() << endl;
        }
    }
};


#endif
