#include<iostream>
using namespace std;
template<class T>
int find(T Array[10],int l,int r,T number)
{
    if((l==r)&&(Array[l]!=number))return (-1);
    int mid=(l+r)/2;
    if(Array[mid]==number)return(mid);
        else if(Array[mid]<number)return(find(Array,mid+1,r,number));
          else return(find(Array,l,mid,number));
}
template<class T>
int find(T Array[10],int n,T number)
{
   return(find(Array,0,9,number));
}
int main(){
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    char b[10] = {'a','b','c','d','e','f','g','h','i','j'};
    double c[10] = {1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2};

    cout<<find(a, 10, 10)<<endl;
    cout<<find(a, 10, 0)<<endl;
    cout<<find(b, 10, 'a')<<endl;
    cout<<find(b, 10, 'k')<<endl;
    cout<<find(c, 10, 1.0)<<endl;
    cout<<find(c, 10, 1.1)<<endl;

    return 0;
}
