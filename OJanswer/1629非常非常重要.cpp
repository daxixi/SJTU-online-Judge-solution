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
    int ans=-1,ansp;
    cin>>n;
    father= new int[n+1]();
    cnt=new int [n+1]();
    head =new node *[n+1];//这个就是邻接表 

    for(int i=1; i<=n ;i++)head[i]=new node(0);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        head[u]->next=new node(v,head[u]->next);
        head[v]->next=new node(u,head[v]->next);
    }
    traverse(1);

    for(int i=1;i<=n;i++)
    {
        int x=0;
        for(node *p=head[i]->next;p!=NULL;p=p->next)
        {
        if(p->id==father[i])
               {if(n-cnt[i]>x)x=n-cnt[i];}
        else
                {if(cnt[p->id]>x)x=cnt[p->id];}
        }

        if(ans==-1||x<ans){ans=x;ansp=i;}
    }
    cout<<ansp<<' '<<ans;
    return 0;
}
