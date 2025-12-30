#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<iostream>
#include<vector>
#include"MenuItem.h"
using namespace std;

class Restaurant{
    private:
        static int restaurantCounter;
        int restaurantId;
        string name;
        string location;
        vector<MenuItem> menu;

    public:
        Restaurant(const string &name, const string &location)
        : name(name), location(location){
            restaurantCounter++;
            this->restaurantId = restaurantCounter;
        }

        // can add getters and setters for other attributes

        void addMenuItem(const MenuItem & menuItem){
            this->menu.push_back(menuItem);
        }

        const vector<MenuItem>& getMenu() const {
            return menu;
        }
};

#endif 