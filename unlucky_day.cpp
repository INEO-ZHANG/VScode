#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

#define MAX 20

void unlucky_day(int w);
int main(){
    int w=0;
    cin>>w;
    unlucky_day(w);
}

void unlucky_day(int w){
    int month_13[]={13,44,72,103,133,164,194,225,256,286,317,347};  //每个月13号距离1.1的日子数
    int i=0;
    for(i=0;i<12;i++){
        if((month_13[i]+w-1)%7==5){
            cout<<(i+1)<<endl;
        }
    }
}