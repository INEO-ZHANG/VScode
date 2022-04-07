#include<stdio.h>
#include<string.h>
#define MAX 1000
int main(){
    char s[MAX];
    char c;
    int i=0;
    while((s[i]=getchar())!='\n'){
        i++;
    }
    s[i]='\0';
    scanf("%c",&c);
    //putchar(c);
    int count=0;
    int len=strlen(s);
    //printf("%s",s);
    for(i=0;i<len;i++){
        if(c>='A'&&c<='Z'){
            if(s[i]==c||s[i]==(c+32)){
            count++;}}
        else if(c>='a'&&c<='z'){
            if(s[i]==c||s[i]==(c-32)){
            count++;}}
        else if(s[i]==c)count++;
    }
    printf("%d",count);
}