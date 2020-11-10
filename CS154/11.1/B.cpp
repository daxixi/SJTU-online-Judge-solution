#include<iostream>
using namespace std;
bool isPrime(int n)
{
    if(n>2)
    {for(int i=2;i<=n-1;i++)
        if(n%i==0)return(false);
    return(true);
    }
    if(n==2)return(true);
    if(n==1)return(false);
}
int main()
{
    int m,n,x;
    x=0;
    cin>>m>>n;
    for(int i=m;i<=n;i++)
        if(isPrime(i))x++;
    cout<<x;
    return 0;
}
