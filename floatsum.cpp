#include<stdio.h>
#include<string.h>
 
int main(){
	int i,j,k,t=0;
	int alen,blen;
	char a[150],b[150];
	int a1[150]={0},b1[150]={0},a2[150]={0},b2[150]={0},ans1[150]={0},ans2[150]={0};
	scanf("%s",&a);
		scanf("%s",&b);
		alen=strlen(a);
		blen=strlen(b);
		for(i=0;i<150;i++){
			a1[i]=0;
			a2[i]=0;
			b1[i]=0;
			b2[i]=0;
			ans1[i]=0;
			ans2[i]=0;
		}
 
		for(i=0;i<alen;i++){
			if(a[i]=='.'){
				k=0;
				for(j=i-1;j>=0;j--){
					a1[k++]=a[j]-'0';
				}
				k=0;
				for(j=i+1;j<alen;j++){
					a2[++k]=a[j]-'0';
				}
			}
		}
		for(i=0;i<blen;i++){
			if(b[i]=='.'){
				k=0;
				for(j=i-1;j>=0;j--){
					b1[k++]=b[j]-'0';
				}
				k=0;
				for(j=i+1;j<blen;j++){
					b2[++k]=b[j]-'0';
				}
			}
		}
		for(i=140;i>0;i--){
			ans1[i]+=a2[i]+b2[i];
			if(ans1[i]>=10){
			    ans1[i-1]+=1;
				ans1[i]-=10;;
			}
		}
		if (ans1[0]!=0) a1[0]=a1[0]+1;
 
		for(i=0;i<=140;i++){
			ans2[i]+=a1[i]+b1[i];
			if(ans2[i]>=10){
				ans2[i]%=10;
				ans2[i+1]+=1;
			}
		}
		for(i=140;i>=0;i--){
			if(ans2[i]!=0){
				for(j=i;j>=0;j--){
					printf("%d",ans2[j]);
				}
				break;
			}
		}
		if(i==-1) printf("0");
        for(i=140;i>0;i--){
			if(ans1[i]!=0){
				break;
			}
		}
        if(i!=0){
		printf(".");
		for(i=140;i>0;i--){
			if(ans1[i]!=0){
				for(j=1;j<=i;j++){
			printf("%d",ans1[j]);
				}
				break;
			}
		}}
}