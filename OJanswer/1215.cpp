#include<iostream>
#include<cstring>
using namespace std;

template<class T>
class priorityQueue{
public:
    priorityQueue(int capacity=100);
    priorityQueue(const T*items,int size);
    //~priorityQueue();
    bool isEmpty()const;
    void enQueue(const T &x);
    T deQueue();
    T getHead()const;
    void print(){for(int i=1;i<=currentsize;i++)cout<<array[i]<<" ";}
private:
    int currentsize;
    T *array;
    int maxsize;

    void doublespace();
    void buildHeap();
    void precolateDown(int hole);
};

template<class T>
priorityQueue<T>::priorityQueue(int capacity)
{
    array=new T[capacity];
    maxsize=capacity;
    currentsize=0;
}

/*template<class T>
priorityQueue<T>::~priorityQueue()
{
    delete []array;
}*/

template<class T>
priorityQueue<T>::priorityQueue(const T*items,int size):maxsize(size+10),currentsize(size)
{
    array=new T[maxsize];
    for(int i=0;i<size;i++)
        array[i+1]=items[i];
    buildHeap();
}

template<class T>
bool priorityQueue<T>::isEmpty()const
{
    return currentsize==0;
}

template<class T>
T priorityQueue<T>::getHead()const
{
    return array[1];
}

template<class T>
void priorityQueue<T>::enQueue(const T&x)
{
    if(currentsize==maxsize-1)doublespace();
    int hole=currentsize+1;
    currentsize++;
    for(;hole>1&&x<array[hole/2];hole/=2)
        array[hole]=array[hole/2];
    array[hole]=x;
}
template<class T>
T priorityQueue<T>::deQueue()
{
     T minItem;
     minItem=array[1];
     array[1]=array[currentsize--];
     precolateDown(1);
     return minItem;
}

template<class T>
void priorityQueue<T>::buildHeap()
{
    for(int i=currentsize/2;i>0;i--)
        precolateDown(i);
}
template<class T>
void priorityQueue<T>::doublespace()
{
    T *tmp=array;
    maxsize*=2;
    array=new T[maxsize];
    for(int i=0;i<=currentsize;i++)
        array[i]=tmp[i];
    delete[]tmp;
}

template<class T>
void priorityQueue<T>::precolateDown(int hole)
{
    int child;
    T tmp=array[hole];
    for(;hole*2<=currentsize;hole=child)
    {
        child=hole*2;
        if(child!=currentsize&&child<currentsize&&array[child+1]<array[child])
            child++;
        if(array[child]<tmp)array[hole]=array[child];
        else break;
    }
    array[hole]=tmp;
}

int main()
{
    priorityQueue<int> Q;
    char a[8];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(strcmp(a,"insert")==0)
            {int x;
            cin>>x;
            Q.enQueue(x);}
            else if(strcmp(a,"delete")==0)Q.deQueue();
               else if(strcmp(a,"min")==0)cout<<Q.getHead()<<endl;
    }
    return 0;
}
