#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include<vector>
#include<string>
#include<algorithm>
#include<pthread.h>
#include "../model/Restaurant.h"

using namespace std;

//singleton class
class RestaurantManager{
    private:
        static pthread_mutex_t lock;
        static RestaurantManager * instance;
        vector<const Restaurant *> restaurants;
        RestaurantManager(){
            //private constructor
        }

    public:

        static RestaurantManager * getInstance(){
            if(instance==nullptr){
                pthread_mutex_lock(&lock);
                if(instance==nullptr) instance = new RestaurantManager();
                pthread_mutex_unlock(&lock);
            }
            return instance;
        }

        void addRestaurant(const Restaurant * r){
            restaurants.push_back(r);
        }

        // const vector<Restaurant *>& searchByLocation(){
        //     can add business logic here
        //     create a new list of and store location, restuarant
        //     then return only the restaurants
        // }

};

#endif