#include<iostream>
using namespace std;
int main()
{
    int m,n,tu,ji;
    cin>>n>>m;
    tu=(m-2*n)/2;
    ji=n-tu;
    if((tu>=0)&&(ji>=0)&&((m-2*n)%2==0))
            cout<<"¼¦£º"<<ji<<"£»ÍÃ£º"<<tu;
        else
            cout<<"ÎÞ½â";
    return 0;
}
