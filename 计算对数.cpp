#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int x;
    long long a,b;
    cin>>a;
    cin>>b;
    for(x=0;x<=20;x++){
        if(pow(a,x)<=b&&pow(a,(x+1))>b)
        {
            cout<<x;
            break;
        }
    }
}