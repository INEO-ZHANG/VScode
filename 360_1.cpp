#include <iostream> 
#include<stdio.h>
#include<string.h>
using namespace std;

#define MAX 100
int main(){
   char S[MAX];
   while(scanf("%s",S)!=EOF){
      //cout<<S<<endl;
      int len=strlen(S);
      //cout<<len<<endl;
      int i=0,j=0;
      int count[5]={0};
      for(i;i<len;i++){
         if(S[i]>='0'&&S[i]<='9'){
            count[0]=1;
         }
         else if(S[i]>='A'&&S[i]<='Z'){
            count[1]=1;
         }
         else if(S[i]>='a'&&S[i]<='z'){
            count[2]=1;
         }
         else {
            count[3]=1;
         }
         if(strlen(S)>=8){
            count[4]=1;
         }
      }
      if(count[0]&&count[1]&&count[2]&&count[3]&&count[4]){
         cout<<"Ok"<<endl;
      }
      else{
         cout<<"Irregular password"<<endl;
      }
   }

}