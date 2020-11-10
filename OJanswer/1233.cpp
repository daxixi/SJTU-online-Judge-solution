#include<iostream>
using namespace std;


struct edgenode
{
    int end;
    edgenode*next;
    edgenode(int e,edgenode*n=NULL){end=e;next=n;}
};
struct vernode
{
    int ver;
    edgenode*head;
    vernode(edgenode*h=NULL){head=h;}
};
int ans=0,M;
bool visit[101];
vernode verlist[101];
void dfs(int i,int dd)
{
    visit[i]=1;
    bool f;
    dd++;if(dd==M)
                if(M!=0){ans++;visit[i]=0;return ;}
                    else{return;}
    edgenode*q=verlist[i].head;
    while(q)
    {
        if(visit[q->end]==0)dfs(q->end,dd);
        q=q->next;
    }
    visit[i]=0;
}
int main()
{

    int d=-1;
    int m,n,s;
    cin>>n>>m>>s>>M;
    for(int i=0;i<101;i++)visit[i]=0;
    for(int i=0;i<m;i++)
    {
        int st,en;
        cin>>st>>en;
        verlist[st].head=new edgenode(en,verlist[st].head);
    }
    dfs(s,d);
    cout<<ans;
}
