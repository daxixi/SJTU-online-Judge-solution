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
    cout<<"��λ������"<<e<<"��ʮλ������"<<d<<"����λ������"<<c<<endl;
    return 0;
}
