#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

class priorityQueue{
public:
    priorityQueue(int capacity=100);
    void enQueue(const int &x);
    ~priorityQueue(){delete[]array;}
    int find(const int &x);
    void decrease(int i, int v);
    void print(){for(int i=1;i<=currentsize;i++)cout<<array[i]<<" ";}
     int currentsize;
private:

    int *array;
    int maxsize;

    void doublespace();
    void precolateDown(int hole);
};

priorityQueue::priorityQueue(int capacity)
{
    array=new int[capacity];
    maxsize=capacity;
    currentsize=0;
}

void priorityQueue::enQueue(const int&x)
{
    if(currentsize==maxsize-1)doublespace();
    int hole=currentsize+1;
    currentsize++;
    for(;hole>1&&x<array[hole/2];hole/=2)array[hole]=array[hole/2];
    array[hole]=x;
}

void priorityQueue::doublespace()
{
    int *tmp=array;
    maxsize*=2;
    array=new int[maxsize];
    for(int i=0;i<=currentsize;i++)
        array[i]=tmp[i];
    delete[]tmp;
}
int priorityQueue::find(const int &x)
{
   int id=-1;
   for(int i=1;i<=currentsize;i++){
    if(array[i]>x){
        if(id==-1||array[i]<array[id]){
            id=i;}
   }
   }
   return id;
}

void priorityQueue::decrease(int i,int v)
{
    int x;
    int hole;
    hole=i;
    x=array[i]-v;
    for(;hole>1&&x<array[hole/2];hole/=2)array[hole]=array[hole/2];
       array[hole]=x;
}
int main()
{
    priorityQueue Q;
    char a[20];
    int n,x,p,v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(strcmp(a,"insert")==0)
            {
            cin>>x;
            Q.enQueue(x);
            }
        if(strcmp(a,"find")==0)
            {
            cin>>x;
            cout<<Q.find(x)<<endl;
            }
        if(strcmp(a,"decrease")==0)
            {
            cin>>p>>v;
            Q.decrease(p,v);
            }
    }
    return 0;
}
