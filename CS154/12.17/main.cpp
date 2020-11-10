#include<iostream>
#include"A.h"
using namespace std;
int main(){

    Date d1, d2;
    int k1, k2;

    cin >> d1 >> k1 >> k2;
    d2 = d1 + k1;
    d1 += k2;
    cout << d1;
    cout<<d2;
    cout<<d2-d1<<endl;
}
