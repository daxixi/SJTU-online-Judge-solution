#include<iostream>
using namespace std;
int search(int *p,int num);
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<search(a,n);
    return 0;
}
int search(int *p,int num)
{
    if(num==1)return(*p);
      else if(search(p,num/2)>search(p+num/2,num-num/2))return (search(p,num/2));
            else return(search(p+num/2,num-num/2));
}
