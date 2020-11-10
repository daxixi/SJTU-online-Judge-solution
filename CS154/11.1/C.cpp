#include<iostream>
using namespace std;
int pn(int n)
{
    int sum;
    sum=0;
    for(int i=1;i<=n-1;i++)
        if(n%i==0)sum+=i;
    return (sum);
}
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=m;i<=n;i++)
        if(pn(i)==i)cout<<i<<endl;
    return 0;
}
