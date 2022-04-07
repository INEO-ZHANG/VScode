#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100

void move(char *s,int pos);
int main(){
    int n ,i=0 ,j=0;
    scanf("%d",&n);
    int N=n;
    int pointpos[10000];
    char s[10000][MAX]={0};
    while(n--){
        scanf("%s",s[i]);
        //printf(" %s",s[i]);
    }
    for(i=0;i<N;i++){       //找出各个数字小数点的位置，储存在pointpos中
        for(j=0;j<strlen(s[i]);j++){//若为整数则记录最后一位的下一位为小数点位置
            if(s[i][j]=='.'){
                pointpos[i]=j;
                break;
            }
            else{
                pointpos[i]=j+1;
            }
        }
    }
    int max=0;
    for(i=0;i<N;i++){
        if(pointpos[i]>max)
            max=pointpos[i];
    }
    n=N;
    while(n--){
        move(s[n],max-pointpos[n]);
    }
    
    return 0;
}

void move(char *s,int pos){
    int i=0;
    int len=strlen(s);
    while(len--){
        s[len+pos]=s[len];
    }
    for(i=0;i<pos;i++){
        s[i]=0;
    }
}