#include<iostream>
using namespace std;

int max(int x,int y)
{
    return x>y? x:y;
}

int main()
{
    int r,a[1001],b[1001],sum=0,tmp;
    cin>>r;
    for(int i=0;i<=1000;i++)
    {
        a[i]=0;b[i]=0;
    }
    for(int i=1;i<=r;i++)
    {
          for(int j=1;j<=i;j++)
          {
              cin>>tmp;
              a[j]=max(b[j],b[j-1])+tmp;
          }
          for(int j=1;j<=i;j++)
            b[j]=a[j];
    }
    for(int i=1;i<=r;i++)
    {
        if(sum<a[i])sum=a[i];
    }
    cout<<sum;
}
