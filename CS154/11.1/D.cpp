#include<iostream>
using namespace std;
int main()
{
    int s,n,base,p,a[100];
    char c[100];
    cin>>n>>base;
    if(base<=10)
    {
        p=1;
        while(n!=0)
        {
            a[p]=n%base;
            n=n/base;
            p++;
        }
        for(int i=p-1;i>=1;i--)
            cout<<a[i];
    }
    else
    {
      p=1;
      while(n!=0)
      {
             s=n%base;
             if(s<10)c[p]='0'+s;
                else c[p]='A'+s-10;
             n=n/base;
             p++;
      }
      for(int i=p-1;i>=1;i--)
          cout<<c[i];
    }
    return 0;
}

