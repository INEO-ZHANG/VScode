#include<stdio.h>
#include<string>
#include<cstring>

#define MAX 1000

int main(){
    char *pdest;
    char str[]="carton",str1[]="carton";
    pdest=strstr(str,str1);
    int l=pdest-str+1;
    printf("%d",l);
}