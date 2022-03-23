#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

int main(){
    int num[15]={0};
    int i = 0, j = 0, count = 0;
    while(cin>>num[i]){      
        i++;
        if(i>14)break;
        if(cin.get()=='\n')break;
    }
    for(i=0;num[i]>0;i++)
        for(j=0;num[j]>0;j++){
            if((num[i]%num[j]==0)&&(num[i]/num[j]==2))
            count++;
        }
    cout<<count;
} 