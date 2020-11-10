#include<iostream>
using namespace std;
int main()
{
    float a,b;
    cin>>a;
    if(a<=10)
        b=1.5*a;
    else
        b=15+2*(a-10);
    cout<<b<<endl;
    return 0;
}
