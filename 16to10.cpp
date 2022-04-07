#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 1000

int main(){
    char s[MAX];
    int i=0;
    while((s[i]=getchar())!='\n')i++;
    s[i]='\0';
    int len=strlen(s);
    int num=0;
    for(i=2;i<len;i++){
        if(s[i]>='A'){
            num+=(int)(s[i]-'A'+10)*pow(16,(len-i-1));
        }
        else
            num+=(int)(s[i]-'0')*pow(16,(len-i-1));
    }
    printf("%d",num);
}