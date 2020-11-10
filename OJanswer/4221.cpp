#include<iostream>
using namespace std;
template<class elemType>
class seqstack
{
    public:
        seqstack(int initialsize=10);
        bool isempty()const;
        void push(const elemType&x);
        elemType pop();
        elemType top()const;
    private:
        elemType *data;
        int maxsize,_top;
        void doublespace();
};
template<class elemType>
seqstack<elemType>::seqstack(int initialsize)
{
    data=new elemType[initialsize];
    maxsize=initialsize;
    _top=-1;
}

template<class elemType>
bool seqstack<elemType>::isempty()const
{
    return _top==-1;
}

template<class elemType>
void seqstack<elemType>::push(const elemType&x)
{
    if(_top==maxsize-1)doublespace();
    data[++_top]=x;
}

template<class elemType>
elemType seqstack<elemType>::pop()
{
    return data[_top--];
}

template<class elemType>
elemType seqstack<elemType>::top()const
{
    return data[_top];
}

template<class elemType>
void seqstack<elemType>::doublespace()
{
    elemType *tmp;
    tmp=new elemType[maxsize*2];
    for(int i=0;i<maxsize;i++)
        tmp[i]=data[i];
    data=tmp;
    delete []tmp;
}








int main(){
int n,sum=0,x;int a,b;
cin>>n;
seqstack<int> zero(n+1);
seqstack<int> one(n+1);
for(int i=0;i<n;i++){cin>>a>>b;
            if(b==0){
                if (one.isempty())zero.push(a);
                            else
                            {
                                while(!one.isempty()&&a>one.top()){x=one.pop();sum++;}
                                if(!one.isempty())sum++;
                                    else zero.push(a);
                            }
                        }
            else one.push(a);
}
cout<<n-sum;
}
