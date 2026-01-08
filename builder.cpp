#include<iostream>
using namespace std;

class HttpRequestBuilder;

class HttpRequest{
    private:
        string name;
        string param;
        string body;

        HttpRequest(){}
    public:

        friend class HttpRequestBuilder;

        void execute(){
            //does some work
        }
};

class HttpRequestBuilder{
    private:
        HttpRequest hr;

    public:

        HttpRequestBuilder& buildWithName(const string & name){
            hr.name = name;
            return *this;
        }

        HttpRequestBuilder& buildWithParam(const string &param){
            hr.param = param;
            return *this;
        }

        HttpRequestBuilder& buildWithBody(const string &body){
            hr.body = body;
            return *this;
        }

        HttpRequest build(){
            // can check for invalid state as well, for example if the name is empty or some other string is not provided
                // if(hr.name.empty()){
                //     throw runtime_error();
                // }
            
            return hr;
        }
};

int main(){
    return 0;
}