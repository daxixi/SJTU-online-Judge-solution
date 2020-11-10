#include<iostream>
using namespace std;
//øÏÀŸ≈≈–Ú
template<class T>
int divide(T a[],int low,int high)
{
    T k=a[low];
    do{while(low<high&&a[high]>=k)high--;
        if(low<high){a[low]=a[high];++low; }
        while(low<high&&a[low]<=k)low++;
        if(low<high){a[high]=a[low];--high;}
    }while(low!=high);
    a[low]=k;
    return low;
}
template<class T>
void quickSort(T a[],int low,int high)
{
    int mid;
    if(low>=high)return;
    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}
template<class T>
void quickSort(T a[],int size){quickSort(a,0,size-1);}
//
int main()
{
    int *a,n,ans=1;
    cin>>n;
    a=new int[n+10];
    for(int i=0;i<n;i++)cin>>a[i];
    quickSort(a,n);
    for(int i=1;i<n;i++)
        if(a[i]>a[i-1])ans++;
    cout<<ans;
}
