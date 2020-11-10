#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,e;
    cin>>a;
    b=a;
    c=b%10;
    b/=10;
    d=b%10;
    b/=10;
    e=b;
    cout<<"百位数字是"<<e<<"，十位数字是"<<d<<"，个位数字是"<<c<<endl;
    return 0;
}
