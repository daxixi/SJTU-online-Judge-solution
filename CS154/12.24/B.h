#include<iostream>
using namespace std;
template <typename T>
class SortList{
    private:
             int p;
             T*Array;
             void qsort(T Array[],int l,int r);
    public:
    SortList(){Array=new T [100000];p=0;}
    void print(); //输出所有元素
     T Kth(int k); //输出第k大元素
    void insert(T a); //插入元素a
    ~SortList(){if (Array)delete[]Array;}
} ;
template<typename T>
void SortList<T>::qsort(T Array[],int l,int r)
{
    int i=l,j=r;
    T mid=Array[(l+r)/2];
    do{
     while(Array[i]>mid)i++;
     while(Array[j]<mid)j--;
     if(i<=j)
     {
         T temp;
         temp=Array[i];
         Array[i]=Array[j];
         Array[j]=temp;
         i++;j--;
     }
    }while (i<=j);
    if(l<j)qsort(Array,l,j);
    if(i<r)qsort(Array,i,r);
}
template<typename T>
void SortList<T>::print()
{
    for(int i=0;i<p;i++)
        cout<<Array[i]<<' ';
    cout<<endl;
}
template<typename T>
T SortList<T>::Kth(int k)
{
    return(Array[k-1]);
}
template<typename T>
void SortList<T>::insert(T a)
{
    Array[p]=a;
    qsort(Array,0,p);
    p++;
}
