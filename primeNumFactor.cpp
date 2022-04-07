#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 2000000014

int main(){
    int num;
    scanf("%d",&num);
    int primenum[12000]={0};
    //int *primenum=(int *)malloc((num/2)*sizeof(int));
    primenum[0]=2;
    int i=0,k=0;
    int flag=0;
    for(i=3;i<=num/2;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            k++;
            if(k>=12000)break;
            primenum[k]=i;
        }
        flag=0;
        if(k>=12000)break;
    }
    i=0;
    int num1=num;
    while(1){
        if(num%primenum[i]==0){
            num=num/primenum[i];
            printf("%d ",primenum[i]);
            if(num>1){
                flag=0;
            for(int j=2;j<num/2;j++){
                if(num%j==0){
                flag=1;
                break;
                }
                if(flag==0)
                {printf("%d",num);
                break;
                }
            }
        }
        if(flag==0)break;;
        }
        else i++;
        if(i>k)break;
    }
    for(int j=2;j<num1;j++){
            if(num1%j==0){
                flag=1;
                break;
            }
        }
    if(flag==0)printf("%d",num1);
    //for(i=0;i<=k;i++)
    //    printf("%d ",primenum[i]);

}