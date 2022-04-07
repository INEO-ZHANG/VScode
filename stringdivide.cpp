#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
    char s[MAX];
    int i=0;
    while((s[i]=getchar())!='\n'){
        i++;
    }
    s[i]='\0';
    int len=strlen(s);
    //printf("%d",len);
    for(i=0;i<len;){
        for(int j=0;j<8;j++){
            if(i>=len)printf("%d",0);
            else if(s[i]!=' '){
            printf("%c",s[i]);
            i++;}
            else
            printf("%d",0);
        }
        printf("\n");
    }
}