#include<iostream>
using namespace std;

class test
{
    public:
    void hello(){
        cout<<"hello world!"<<endl;
    }
};

int main(){
    test T1;
    T1.hello();
}