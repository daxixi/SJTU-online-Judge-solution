#include<iostream>
using namespace std;
int main()
{
    string a;
    cin>>a;
    if((a[0]==a[4])&&(a[1]==a[3]))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
