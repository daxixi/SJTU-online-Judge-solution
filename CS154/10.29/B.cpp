#include<iostream>
using namespace std;
int main()
{
    const int maxn=100;
    int a[maxn][maxn],m,n,c,p;
    bool f,d;
    cin>>m>>n;
    d=false;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
              cin>>a[i][j];
    for(int i=0;i<m;i++)
    {
        c=a[i][1];p=1;
        for(int j=0;j<n;j++)
            if(a[i][j]>c)
        {
        c=a[i][j];
        p=j;
        }
        f=true;
        for(int j=0;j<m;j++)
            if(a[j][p]<a[i][p])f=false;
        if(f)
        {
            cout<<"mat["<<i<<"]["<<p<<"]="<<c;
            d=f;
        }
    }
    if(!d)cout<<"Not Found";
    return 0;
}
