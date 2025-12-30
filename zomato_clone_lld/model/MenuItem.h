#ifndef MENUITEM_H
#define MENUITEM_H

#include<iostream>
#include<string>
using namespace std;

class MenuItem{
    private:
        string code;
        string name;
        int price;
    public:
        
        MenuItem(const string &code, const string &name, int price) : code(code), 
        name(name), price(price){};\

        string getCode() const{
            return this->code;
        }

        void setCode(string const &code){
            this->code = code;
        }

        string getName() const{
            return this->name;
        }

        void setName(string name){
            this->name = name;
        }

        int getPrice() const{
            return this->price;
        }

        void setPrice(int p){
            price = p;
        }
};

#endif