#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,s[4],b;
    cin>>a;
    b=a;
    for(int i=1;i<=4;i++)
       {
        s[i]=b%10;
        b/=10;
       }
    for(int i=4;i>=1;i--)printf("%c",s[i]+13+64);
    return 0;
}
