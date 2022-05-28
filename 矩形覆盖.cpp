#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,ans=0x7fffffff;
struct node{
    int x,y;
    bool operator < (const node b)const{
        if(x==b.x)return y<b.y;
        return x<b.x;
    }
}a[1000];
struct Node{
    int x1,y1,x2,y2;
}be[5];
void dfs(int pos,int cnt,int sum){
    if(sum>=ans)return;
    if(pos>n){
        ans=min(ans,sum);
        return;
    }
    if(cnt>k)return;
    be[cnt].x1=be[cnt].x2=a[pos].x;
    be[cnt].y1=be[cnt].y2=a[pos].y;
    for(int i=pos;i<=n;i++){
        be[cnt].x1=min(be[cnt].x1,a[i].x);
        be[cnt].y1=min(be[cnt].y1,a[i].y);
        be[cnt].x2=max(be[cnt].x2,a[i].x);
        be[cnt].y2=max(be[cnt].y2,a[i].y);
        for(int j=1;j<cnt;j++){
            if(be[cnt].x1==be[j].x2&&be[cnt].y1<=be[j].y2)return;
        }
        dfs(i+1,cnt+1,sum+(be[cnt].x2-be[cnt].x1)*(be[cnt].y2-be[cnt].y1));
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].y,&a[i].x);
    sort(a+1,a+n+1);
    dfs(1,1,0);
    printf("%d",ans);
}