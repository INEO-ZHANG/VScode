#include<iostream>
using namespace std;

int main(){
    int n,a1,a2,a3,A1=0,A2=0,A3=0;
    cin>>n;
    for(a1=n;a1>=0;a1--)
        for(a2=n;a2>=0;a2--)
            for(a3=n;a3>=0;a3--){
                if((a1+a2)%2==0)
                    if((a2+a3)%3==0)
                        if((a1+a2+a3)%5==0){
                            if(a1+a2+a3>A1+A2+A3){
                                A1=a1;A2=a2;A3=a3;
                            }
                            if(a1+a2+a3==A1+A2+A3){
                                if(a1>A1){
                                A1=a1;A2=a2;A3=a3;
                                }
                                else if(a1==A1){
                                    if(a2>A2){
                                A1=a1;A2=a2;A3=a3;
                                    }
                                }
                            }
                        }
            }
    cout<<A1<<' '<<A2<<' '<<A3;
}