
#include<iostream>
using namespace std;
int sum;
void f(int x,int y)
{
    for(int i=x;i<y;i++)
    {
        if(y%i==0&&i<=y/i)
        {
            sum++;
            f(i,y/i);
        }
        if(i>y/i)
            return;
    }
}
int main()
{
    sum=1;
    int n;
    cin>>n;
    f(2,n);
    cout<<sum<<endl;
    return 0;
}