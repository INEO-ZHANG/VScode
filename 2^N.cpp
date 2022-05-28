#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    if(N>50){
        int out[50]={0};
        out[49]=1;
        int flag=0;
        for(int i=0;i<N;i++){
            for(int j=49;j>0;j--){
                out[j]=out[j]*2+flag;
                flag=out[j]/10;
                out[j]=out[j]%10;
            }
        }
        int i=0;
        while(out[i]==0)i++;
        //cout<<i;
        for(;i<50;i++)cout<<out[i];
    }
    else{
    long long num;
    num=pow(2,N);
    cout<<num;
    }
}