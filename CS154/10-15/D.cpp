#include<iostream>
using namespace std;
int main()
{
    float x1,y1,x2,y2,x3,y3;
    double k,b;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    k=(y2-y1)/(x2-x1);
    b=y1-k*x1;
    if(y3==k*x3+b)cout<<"YES";
        else cout<<"NO";
    return 0;
}
