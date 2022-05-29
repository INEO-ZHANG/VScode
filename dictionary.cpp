#include<stdio.h>
#include<string.h>
#define MAX 100000

int main(){
    char s[MAX][10],t[MAX][10];
    int i=0,j=0;
<<<<<<< HEAD
    while(scanf("%s%s",s[i],t[i])){
        if(s[i][0]=='\n'||s[i][0]=='\0')break;
        printf("%s %s",s[i],t[i]);
        i++;
    }    
    while(i--){
        printf("%s%s",s[i],t[i]);
    }
}
=======
   
    /*while(i<MAX){
    while((s[i][j]=getchar())!=' '){
        j++;
    }
    s[i][j]='\0';
    //printf("s:%s",s[i]);
    //printf("\nlength:%d",strlen(s[i]));
    
    if(strlen(s[i])==0){
        break;
    }
    j=0;
    while((t[i][j]=getchar())!='\n'){
        j++;
    }
    t[i][j]='\0';
    j=0;
    printf("s:%s t:%s\n",s[i],t[i]);
    i++;
    getchar();
    }*/
    while(1){
        s[i][0]=getchar();
        if(s[i][0]=='\n')break;
        scanf("%s%s",s[i]+1,t[i]);
        //printf("s:%s t:%s\n",s[i],t[i]);
        i++;
        getchar();
       // getchar();
    }
    int length=i;

    //getchar();
    char d[1000][10];
    i=0;
    j=0;
   /* while(1){
        d[i][0]=getchar();
        if(d[i][0]=='\n')break;
        scanf("%s",d[i]+1);
        printf("d:%s\n",d[i]);
        i++;
        getchar();
        //getchar();
    }*/
    while(scanf("%s",d[i])!=EOF)i++;
    /*while(i<MAX){
    while((d[i][j]=getchar())!='\n'){
        j++;
    }
    d[i][j]='\0';
    
    if(strlen(d[i])==0){
        break;
    }
    printf("d:%s",d[i]);
    i++;
    j=0;
    }*/
    int l=i;
    int flag=0;
    for(i=0;i<l;i++){
        for(j=0;j<length;j++){
            if(strcmp(t[j],d[i])==0){
                flag=1;
                printf("%s\n",s[j]);
            }
        }
        if(flag==0){
            printf("eh\n");
        }
        flag=0;
    }
}
>>>>>>> 2875718e46fb700784adc0f2dfad7b38d5c63a3a
