#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<stdlib.h>
#include<iomanip>
using namespace std;

int main(){
    long double num=0 ;
    string ntos;
    cin>>ntos;
    int len=ntos.length();

    for(int i=2;i<len;i++){
        long double a=(ntos[i]-'0'),b=pow(8.0,i-1);
        num+=a/b;
    }
    cout<<setprecision(19)<<num;

}