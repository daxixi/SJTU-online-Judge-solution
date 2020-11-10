#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    for(int i=1;i<=((x+1)/2-1);++i)
    {
        for(int j=1;j<=((x+1)/2-i);++j)cout<<' ';
        for(int j=1;j<=(2*i-1);j++)cout<<'*';
            cout<<endl;
    }
    for(int i=1;i<=x;i++)cout<<'*';
    cout<<endl;
    for(int i=((x+1)/2+1);i<=x;++i)
    {
        for(int j=1;j<=(i-(x+1)/2);j++)cout<<' ';
        for(int j=1;j<=(x-(i-(x+1)/2)*2);j++)cout<<'*';
        cout<<endl;
    }
    return 0;
}
