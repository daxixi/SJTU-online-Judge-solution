#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int d,node *n=NULL){data=d;next=n;}
    };

int main()
{
    node *head,*p,*q;
    int n,i,m;
    int k=0,ans;
    cin>>n>>m>>k;
    head=p=new node(0);
    for(i=1;i<n;++i)
        p=p->next=new node(i);
    p->next=head;

    q=head;
    if(m==1){cout<<k;return 0;}
        else
    while(q->next!=q&&k)
    {
        for(int j=m-2;j>0;--j)
        {
          p=q->next;
          q=p;
        }
        p=q->next;
        q->next=p->next;
        ans=p->data;
        delete p;
        q=q->next;
        k--;
    }
    cout<<ans+1;
    return 0;
}

