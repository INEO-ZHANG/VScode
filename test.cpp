<<<<<<< HEAD
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
=======
#include<stdio.h>
#include<string>
#include<cstring>

#define MAX 1000

int main(){
    char *pdest;
    char str[]="carton",str1[]="carton";
    pdest=strstr(str,str1);
    int l=pdest-str+1;
    printf("%d",l);
>>>>>>> 2875718e46fb700784adc0f2dfad7b38d5c63a3a
}