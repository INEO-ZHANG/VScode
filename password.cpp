#include<stdio.h>
#include<string.h>

#define MAX 200

int main(){
    int n,i=0;
    scanf("%d",&n);
    int a[MAX];
    getchar();
    for(i=0;i<n;i++){
        scanf("%d",a+i);
        //printf("%d",a[i]);
    }
    int k;
    getchar();
    scanf("%d",&k);
    char s[MAX],s1[MAX]="0";
    i=0;
    getchar();
    while((s[i]=getchar())!='\n'){
        //printf("%c",s[i]);
        i++;
    }
    s[i]='\0';
    for(int j=0;j<n-i-1;j++){
        s[j]=' ';
    }
   
    int A[MAX];
    for(i=0;i<n;i++){
            A[i]=i;
        }
    for(i=0;i<n;i++){
            a[i]--;
        }
    while(k--){
        for(i=0;i<n;i++){
            A[i]=a[A[i]];
        }

    }
    //printf("\n");
    for(i=0;i<n;i++){
        s1[A[i]]=s[i];
        if(s[i]==' '){}
        //printf("%c",s1[i]);
    }
    for(i=0;i<n;i++){
        printf("%c",s1[i]);
    }
    
}