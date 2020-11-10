#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int stack0[100001];
int top=-1;
void push(const int&x)
{
    top++;
    stack0[top]=x;
}
void pop()
{
    top--;
}
void print()
{
    for(int i=0;i<top+1;i++)
        cout<<stack0[i]<<' ';
}

class DisjointSet
{
private:
    int size0;
    int *parent;
public:
    DisjointSet(int s);
    ~DisjointSet(){delete[]parent;}
    void Union(int root1,int root2);
    int Find(int x);
};

DisjointSet::DisjointSet(int n)
{
    size0=n;
    parent=new int[size0];
    for(int i=0;i<size0;++i)parent[i]=-1;
}

int DisjointSet::Find(int x)
{
    if(parent[x]<0)return x;
    int r;
    r=x;
    while(parent[r]>=0)r=parent[r];
    return r;

}
 int r[100001];//表示在第几行
 bool visit[100001];
   int p0[100001],p1[100001],p2[100001],p3[100001];
 int size0=0,e;
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
//产生路径
void dfs(int i)
{
    visit[i]=1;
    push(i);
    if(i==e)print();
    if(p0[i]!=0&&visit[p0[i]]==0)dfs(p0[i]);
    if(p1[i]!=0&&visit[p1[i]]==0)dfs(p1[i]);
    if(p2[i]!=0&&visit[p2[i]]==0)dfs(p2[i]);
    if(p3[i]!=0&&visit[p3[i]]==0)dfs(p3[i]);
    pop();
    visit[i]=0;
}
int main()
{
 int n,s;

 cin>>n>>s>>e;
 for(int i=0;i<n+100;i++)
 {
     p0[i]=0;p1[i]=0;p2[i]=0;p3[i]=0;
     stack0[i]=0;
 }
 for(int i=1;i<=n;i++)
    for(int  j=i*(i+1)/2-i+1;j<=i*(i+1)/2;j++)
        {
            size0++;
            r[size0]=i;}
  DisjointSet S(size0+10);
//开始砸墙
 int x,p,tar;
 while(true)
    {
        cin>>x>>p;
        switch(p){
        case 0:tar=x-r[x];if(tar<=0||r[tar]!=r[x]-1)tar=-1;else {p0[x]=tar;p3[tar]=x;}break;
        case 1:tar=x-r[x]+1;if(tar<=0||r[tar]!=r[x]-1)tar=-1;else {p1[x]=tar;p2[tar]=x;}break;
        case 2:tar=x+r[x];if(tar>size0||r[tar]!=r[x]+1)tar=-1;else {p2[x]=tar;p1[tar]=x;}break;
        case 3:tar=x+r[x]+1;if(tar>size0||r[tar]!=r[x]+1)tar=-1;else {p3[x]=tar;p0[tar]=x;}break;
        }
        if(tar!=-1)S.Union(S.Find(x),S.Find(tar));
        if(S.Find(s)==S.Find(e)){dfs(s);break;}
    }
}
