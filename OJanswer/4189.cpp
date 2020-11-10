#include <iostream>

using namespace std;
struct node
{
    int id;
    node *next;
    node (int _id,node *_next=NULL):id(_id),next(_next){}
};
int n;
int *father,*cnt;
node **head;

void traverse(int x)
{
    for(node *p=head[x]->next;p!=NULL;p=p->next)
    {
        if(father[p->id]==0&&p->id!=1)
        {
            father[p->id]=x;
            traverse(p->id);
            cnt[x]+=cnt[p->id];
        }
    }
    ++cnt[x];
}
int main()
{
   // int ans=-1,ansp;
    cin>>n;
    father= new int[n+1]();
    cnt=new int [n+1]();
    head =new node *[n+1];
    int *ans;
    ans=new int[n+1];
    int pos=0;
    for(int i=1; i<=n ;i++)head[i]=new node(0);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        head[u]->next=new node(v,head[u]->next);
        head[v]->next=new node(u,head[v]->next);
    }
    traverse(1);
    int x=n/2;
    for(int i=1;i<=n;i++)
    {
        bool t=true;
        for(node *p=head[i]->next;p!=NULL;p=p->next)
        {
        if(p->id==father[i])
               {if(n-cnt[i]>x)t=false;}
        else
                {if(cnt[p->id]>x)t=false;}
        }
        if(t){
            ans[pos]=i;
            pos++;
        }
    }
    for(int i=0;i<pos;i++)
        cout<<ans[i]<<' ';
    return 0;
}

