#include<iostream>
using namespace std;

int main(){
    int s,na,nb,a[10000],b[10000];
    int num=0;
    cin>>s;
    cin>>na;
    for(int i=0;i<na;i++)
        cin>>a[i];
    cin>>nb;
    for(int i=0;i<nb;i++)
        cin>>b[i];
    
    for(int i=0;i<na;i++)
        for(int j=0;j<nb;j++)
            if(a[i]+b[j]==s)num++;

    cout<<num;
}