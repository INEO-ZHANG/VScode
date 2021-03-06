#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n;
    cin>>n;
    int matrix[n][n],sum[n],dp[n],maxSum;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    maxSum=matrix[0][0];
    for(int i=0;i<n;i++){
        memset(sum,0,sizeof(sum));
        for(int j=i;j<n;j++){
            for(int k=0;k<n;k++)
                sum[k]+=matrix[j][k];
            dp[0]=sum[0];
            maxSum=max(dp[0],maxSum);
            for(int k=1;k<n;k++){
                dp[k]=max(sum[k],dp[k-1]+sum[k]);
                maxSum=max(dp[k],maxSum);
            }
        }
    }
    cout<<maxSum<<endl;
    return 0;
}