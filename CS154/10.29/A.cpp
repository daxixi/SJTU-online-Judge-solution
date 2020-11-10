#include<iostream>
using namespace std;
void qsort(int,int);
 int a[1000],n;
int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    qsort(1,n);
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    return 0;
}
void qsort(int l,int r)
{
    int mid=a[(l+r)/2],tmp,i=l,j=r;
    do{
       while(a[i]>mid)i++;
       while(a[j]<mid)j--;
        if(i<=j)
        {
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++;
            j--;
        }
       }while(i<=j);
       if(i<r)qsort(i,r);
       if(j>l)qsort(l,j);
}
