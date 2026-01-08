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

class nameBuilder;
class paramBuilder;
class bodyBuilder;


class NameBuilder{
    public: 
        virtual paramBuilder& buildWithName(const string & name) = 0;
};

class paramBuilder{
    public:
        virtual bodyBuilder& buildWithParam(const string & param) = 0;
};

class bodyBuilder{
    public:
        virtual bodyBuilder& buildWithBody(const string & body) = 0; 
        virtual HttpRequest build() = 0;
};

class HttpRequestBuilder: public NameBuilder, public paramBuilder, public bodyBuilder{
    private:
        HttpRequest hr;

    public:

        paramBuilder& buildWithName(const string &name) override{
            hr.name = name;
            return *this;
        }

        bodyBuilder& buildWithParam(const string & param) override{
            hr.param = param;
            return * this;
        }

        bodyBuilder& buildWithBody(const string & body) override{
            hr.body = body;
            return *this;
        }

        HttpRequest build() override{
            return hr;
        }
};




int main(){
    return 0;
}