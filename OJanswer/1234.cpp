#include<iostream>
#define noedge 0x7fffffff
using namespace std;

class DisjointSet
{
private:
    int size;
    int *parent;
public:
    DisjointSet(int s);
    ~DisjointSet(){delete[]parent;}
    void Union(int root1,int root2);
    int Find(int x);
};

DisjointSet::DisjointSet(int n)
{
    size=n;
    parent=new int[size];
    for(int i=0;i<size;++i)parent[i]=-1;
}

int DisjointSet::Find(int x)
{
    if(parent[x]<0)return x;
    return parent[x]=Find(parent[x]);
}

void DisjointSet::Union(int root1,int root2)
{
    if(root1==root2)return;
    if(parent[root1]>parent[root2]){
        parent[root2]+=parent[root1];
        parent[root1]=root2;
    }
    else{
        parent[root1]+=parent[root2];
        parent[root2]=root1;
    }
}


struct edgenode{
        int weight;
        int _begin;
        int _end;
        edgenode*next;
        edgenode(int b,int e,int w,edgenode*n=NULL){
                 _begin=b;
                 _end=e;
                 weight=w;
                 next=n;
                 }
                };

struct vernode{
      edgenode* head;
      vernode(edgenode*h=NULL){
            head=h;}
      };

struct edge{
        int weight;
        int _begin;
        int _end;
        bool operator<(const edge&x){return weight<x.weight;}
        bool operator>(const edge&x){return weight>x.weight;}
        bool operator<=(const edge&x){return weight<=x.weight;}
        bool operator>=(const edge&x){return weight>=x.weight;}
        edge&operator=(const edge&x){weight=x.weight;_begin=x._begin;_end=x._end;return *this;}
        };

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
int main()
{
    int vnum,ednum;
    cin>>vnum>>ednum;
    vernode *verlist;
    verlist=new vernode[vnum+1];
    int u,v,w;
    edge ee[ednum];
    for(int i=0;i<ednum;i++)
        {
            cin>>u>>v>>w;
            verlist[u].head=new edgenode(u,v,w,verlist[u].head);
            verlist[v].head=new edgenode(v,u,w,verlist[v].head);
            ee[i]._begin=u;ee[i]._end=v;ee[i].weight=w;
        }
    DisjointSet S(vnum+10);
    quickSort<edge>(ee,0,ednum-1);
    int ans=0;
    int c=0,ep=0;
    while(c<vnum-1)
    {
        edge tmpe;
        tmpe=ee[ep];
        if(S.Find(tmpe._begin)!=S.Find(tmpe._end))
        {
            ans+=tmpe.weight;
            S.Union(S.Find(tmpe._begin),S.Find(tmpe._end));
            c++;
        }
        ep++;
    }
    cout<<ans;
}
