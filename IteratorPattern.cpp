#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Iterator{
    public:
        virtual bool hasNext() = 0;
        virtual T next() = 0;
};


template<typename T>
class Iterable{
    public:
        virtual Iterator<T>* giveIterator()  = 0; 
};

class LinkedList : Iterable<int>{
    public:
        LinkedList * next;
        int value;

    public:

        LinkedList(int value){
            this->value = value;
        }

        Iterator<int>* giveIterator() override;
};

class LinkedListIterator : public Iterator<int>{
    private:
        LinkedList * head;
    public:

        LinkedListIterator(LinkedList * head){
            this->head = head;
        }

        bool hasNext() override{
            if(head->next == nullptr) return false;
            return true;
        }

        int next() override{
            int value = head->value;
            head = head->next;
            return value;
        }
};

Iterator<int> * LinkedList::giveIterator(){
    return new LinkedListIterator(this);
}

class PlayListIterator :public Iterator<int>{
        vector<int> v;
        int index;
    public:
        PlayListIterator(vector<int> &v){
            this->v = v;
            index = 0;
        }

        bool hasNext() override{
            if(index==v.size()-1) return false;
            return true;
        }

        int next() override{
            int value = v[index];
            index++;
            return value;
        }

};  

class PlayList : public Iterable<int>{
    private:
        vector<int> songs;
    public: 
        Iterator<int> * giveIterator(){
            return new PlayListIterator(songs);
        }
};