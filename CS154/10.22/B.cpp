#include<iostream>
using namespace std;
int main()
{
    int t,m;
    cin>>m;
    t=0;
    for(int x1=1;x1<=m;x1++)
        for(int x2=1;x2<=m;x2++)
          for(int x3=1;x3<=m;x3++)
             if((x1+x2*2+x3*5)==m)t++;
    cout<<t<<endl;
    return 0;
}
