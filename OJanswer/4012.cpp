#include<iostream>
using namespace std;

class hfTree{
    private:
        struct Node
        {
            int weight;
            int parent,left,right;
        };

    Node *elem;
    int length;
    public:
        int answer;
        hfTree(const int *w,int size);
        int getlength(){return length;}
    };

hfTree::hfTree(const int *w,int size)
{

    const int maxint=2147483647;
    answer=0;
    int min1,min2;
    int x,y;

    length=2*size;
    elem=new Node[length];

    for(int i=size;i<length;i++)
    {
       elem[i].weight=w[i-size];
       elem[i].parent=elem[i].left=elem[i].right=0;
    }

    for(int i=size-1;i>0;i--)
    {
        min1=min2=maxint;
        x=y=0;
        for(int j=i+1;j<length;j++)
           if(elem[j].parent==0)
            if(elem[j].weight<min1)
           {
                min2=min1;
                x=y;
                min1=elem[j].weight;
                y=j;
           }
           else if(elem[j].weight<min2)
           {
               x=j;
               min2=elem[j].weight;
           }
    elem[i].weight=elem[x].weight+elem[y].weight;
    answer+=elem[i].weight;
    elem[i].parent=0;
    elem[i].left=x;
    elem[i].right=y;
    elem[x].parent=i;
    elem[y].parent=i;
    }
}

int main()
{
    int n;cin>>n;
    int *data;
    data=new int[n];
    for(int i=0;i<n;i++)
        cin>>data[i];
    hfTree t(data,n);
    cout<<t.answer;
}
