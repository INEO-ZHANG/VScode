#include<stdio.h>
#include<string.h>
#define MAX 100000

int main(){
    char s[MAX][10],t[MAX][10];
    int i=0,j=0;
    while(scanf("%s%s",s[i],t[i])){
        if(s[i][0]=='\n'||s[i][0]=='\0')break;
        printf("%s %s",s[i],t[i]);
        i++;
    }    
    while(i--){
        printf("%s%s",s[i],t[i]);
    }
}