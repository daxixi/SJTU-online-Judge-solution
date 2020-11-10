#include<iostream>
using namespace std;
int main()
{
    const int maxn=10000;
    bool f[maxn]={0};
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            if((j%i)==0)f[j]=!f[j];
    for(int i=1;i<=n;i++)
        if(f[i])cout<<i<<' ';
    return 0;
}
