#include<iostream>
using namespace std;
int search(int *p,int n,int key);
 int main()
 {
     int n;
     cin>>n;
     int *arr=new int[n];
     for(int i=0;i<n;i++)cin>>arr[i];
     int key;
     cin>>key;
     if(search(arr,n,key)!=-1)cout<<search(arr,n,key);
        else cout<<"Not Found";
     delete []arr;
     return 0;
 }
int search(int *p,int n,int key)
{
    for(int i=0;i<=n-1;i++)
        if(p[i]==key)return(i);
return(-1);
}
