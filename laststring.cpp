#include<stdio.h>
#include<string.h>
#define MAX 5000
int main(){
    char s[MAX];
    int i=0,count=0;
    while((s[i]=getchar())!='\n'){
        i++;
    }
    s[i]='\0';
    i=0;
    int len=strlen(s);
    i=len-1;
    while(i>=0){
        if(s[i]!=' ')
        count++;
        else break;
    i--;
    }
    //printf("%d",len);
    //printf("%s",s);
    printf("%d",count);
}