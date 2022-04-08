#include<stdio.h>
#include<string>
#include<cstring>

#define MAX 1000

int main(){
    int i=0,j=0;
    char S[MAX][20],s1[MAX][20];
    while(scanf("%s",S[i])!=EOF){
        //printf("%s",S[i]);
        i++;
    }
    int len=i;
    /*for(i=0;i<len;i++){
        printf("%s\n",S[i]);
    }*/
    
    int flag=1;
    //char *pdest;
    for(i=0;i<len;i++){
        for(j=1;j<=strlen(S[i]);j++){
            char tem[20];
            memset(tem,'\0',sizeof(tem));
            strncpy(tem,S[i],j);
            tem[j]='\0';
            for(int k=0;k<len;k++){
                if(k!=i){
                if(strstr(S[k],tem)==S[k]){
                    flag=1;break;
                }}
            }
            if(flag==0||j==strlen(S[i])){
                //strcpy(s1[i],tem);
                for(int m=0;m<j;m++){
                    s1[i][m]=S[i][m];
                }
                break;
            }

            flag=0;
            memset(tem,'\0',sizeof(tem));
        }
        printf("%s %s\n",S[i],s1[i]);
        
    }
    printf("\n");
}