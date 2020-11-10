#include<iostream>
using namespace std;
int main()
{
    long long sum=0,v=1;
    for(int i=1;i<=10;++i)
    {
        v*=i;
        sum+=v;
    }
    cout<<sum<<endl;
    return 0;
}
