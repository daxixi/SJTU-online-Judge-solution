#include<iostream>
using namespace std;
#include<cstring>
#include<stdio.h>
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
    char c[10000],cc[100];
    int *q;
    q=new int[10000000]();
    int n,x;
    int max=0;
    char maxn[1000];
    strcpy(maxn,"");
    while(true)
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
        if(strcmp(cc,"finish")==0)return 0;
        if(strcmp(cc,"query")==0){
            printf("%d",max);
            cout<<' ';
            puts(maxn);
        }
        if(strcmp(cc,"cite")==0)
        {
            t=0;
            c[0]=getchar();
            while(c[t]!='\n'&&c[t]!='\0'&&c[t]!='\r')
                    {
                        t++;
                        c[t]=getchar();
                    }c[t]='\0';
            x=0;
            x=tree.map(c);
            q[x]++;
            if(q[x]>max||(q[x]==max&&strcmp(c,maxn)<0)){strcpy(maxn,c);max=q[x];}
        }
    }

}
