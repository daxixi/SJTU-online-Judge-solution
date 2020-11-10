#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    float x1,x2,y1,y2,t;
    cin>>x1>>y1>>x2>>y2;
    t=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    cout<<setiosflags(ios::fixed);
    cout<<setprecision(2)<<t<<endl;
return0£»
}
