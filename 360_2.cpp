#include <iostream> 
#include<stdio.h>
#include<string.h>
using namespace std;

#define MAX 1000
int main(){
    int n1,n2,n3;
    scanf("%d %d %d",&n1,&n2,&n3);
    char I[MAX][20],am[MAX][20],yours[MAX][20];
    for(int i=0;i<n1;i++){
        scanf("%s",I[i]);
        //cout<<I[i];
    }
    for(int i=0;i<n2;i++){
        scanf("%s",am[i]);
        //cout<<am[i];
    }
    for(int i=0;i<n3;i++){
        scanf("%s",yours[i]);
        //cout<<yours[i];
    }
    int m;
    cin>>m;
    //cout<<m;
    char S[20][100];
    int j=0;
    
    getchar();
    for(int i=0;i<m;i++){
        int check[3]={0};
        j=0;
        while((S[i][j]=getchar())!='\n'){
        j++;
    }
    S[i][j]='\0';
    for(int m=0;m<n1;m++){
        if(strstr(I[m],S[i])){
            check[0]++;
        }
    }
    for(int m=0;m<n2;m++){
        if(strstr(am[m],S[i])){
            check[1]++;
        }
    }
    for(int m=0;m<n3;m++){
        if(strstr(I[m],S[i])){
            check[2]++;
        }
    }
    if(check[0]>0&&check[1]==1&&check[2]>0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }
    

}