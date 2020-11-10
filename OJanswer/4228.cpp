#include<iostream>
using namespace std;
#include<cstring>
#include<stdio.h>
struct Node
{
    Node*next;
    char data[100];
    Node(char _data[]="",Node*_next=NULL){next=_next;strcpy(data,_data);}
};

class TREE
{
    struct node{
    char data[10000];
    node*left;
    node*right;
    int num;
    node(char _data[]="",node*_left=NULL,node*_right=NULL)
          {strcpy(data,_data);left=_left;right=_right;}
    };
    node*root;
    int p;
public:
    TREE(node*t=NULL){root=t;p=0;}
    int map(char x[]){return map(x,root);}
private:
    int map(char x[],node*&t);
};

int TREE::map(char x[],node*&t)
{
    if(t==NULL)
       {t=new node(x);
       p++;
       t->num=p;
       return p;
       }
    else if(strcmp(x,t->data)<0)return(map(x,t->left));
    else if(strcmp(x,t->data)>0)return(map(x,t->right));
    else return t->num;
}
int main()
{
    TREE tree;
    Node*a[100001];
    char c[1000],cc[100];
    int *numq,*numh;
    numq=new int[10000000]();
     numh=new int[10000000]();
    int n,x,p=0,tmpp;
    cin>>n;cin.get();
    for(int i=0;i<n;i++)
    {
        strcpy(cc,"");
        strcpy(c,"");
        int t=0;
        cc[0]=getchar();
        while(cc[t]!=' '&&cc[t]!='\n'&&cc[t]!='\0'&&cc[t]!='\r')
            {
                t++;
            cc[t]=getchar();
            }cc[t]='\0';
         t=0;
        c[0]=getchar();
        while(c[t]!=' '&&c[t]!='\n'&&c[t]!='\0'&&c[t]!='\r')
            {
                t++;
            c[t]=getchar();
            }c[t]='\0';
        x=0;
    x=tree.map(c);
    if(numh[x]==0){p++;numq[p]=x;numh[x]=p;
                    a[p]=new Node(cc,NULL);
                    }
                    else
                        {
                        Node*tmp;
                    tmp=a[numh[x]];
                    while(tmp->next)
                    {
                        tmp=tmp->next;
                    }
                    tmp->next=new Node(cc,NULL);
                        }
    }
    for(int i=1;i<=p;i++)
    {
        Node*tmp;
        tmp=a[i];
        while(tmp){cout<<tmp->data;cout<<' ';tmp=tmp->next;}
        cout<<'\n';
    }
}
