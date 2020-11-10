#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,n,sum,f,t,i;
    cin>>a>>n;
    sum=0;
    for(i=1;i<=n;i++)
     {
         f=0;
         for(int j=1;j<=i;j++)
            f=f+a*pow(10,j-1);
        sum+=f;
     }
     cout<<sum<<endl;
     return 0;
}
