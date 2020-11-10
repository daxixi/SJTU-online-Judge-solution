#include<iostream>
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


int main()
{
    int m,n,ans=0,tn,t,tx;
    cin>>n>>m;
    DisjointSet S(n);
    for(int i=0;i<m;i++)
    {
        cin>>tn;
        cin>>t;
        for(int j=0;j<tn-1;j++)
        {
            cin>>tx;
            S.Union(S.Find(t),S.Find(tx));
        }
    }
    for(int i=0;i<n;i++)
        if(S.Find(0)==S.Find(i))ans++;
    cout<<ans;
}
