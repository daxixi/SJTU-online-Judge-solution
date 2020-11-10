#include<iostream>
#include<cstring>
using namespace std;


template<class T>
class bts{
private:
    struct node{
    T data;
    node*left;
    node*right;
    node(const T&_data,node*_left=NULL,node*_right=NULL):data(_data),left(_left),right(_right){}
    };
    node *root;
    void insert(const T&x,node*&t);
    void remove(const T&x,node*&t);
    bool find(const T&x,node*t)const;
    void makeEmpty(node*t);
    int find_ith(node*t,T&x,int &answer);
    void delsmall(const T&x,node*&t);
    void delbig(const T&x,node*&t);
    void delbs(const T&x,const T&y,node*&t);
public:
    bts(node*t=NULL){root=t;}
    bool find(const T&x){return find(x,root);}
    void insert(const T&x){insert(x,root);}
    void remove(const T&x){remove(x,root);}
    int  find_ith(T&x){int answer=-1;return(find_ith(root,x,answer));}
    void delsmall(const T&x){delsmall(x,root);}
    void delbig(const T&x){delbig(x,root);}
    void delbs(const T&x,const T&y){delbs(x,y,root);}
};

template<class T>
bool bts<T>::find(const T&x,node*t)const
{
    if(t==NULL)return false;
    else if(x<t->data)return find(x,t->left);
        else if (x>t->data)return find(x,t->right);
            else return true;
}

template<class T>
void bts<T>::insert(const T&x,node*&t)
{
    if(t==NULL)t=new node(x);
        else if(x<t->data)insert(x,t->left);
            else insert(x,t->right);
}

template<class T>
void bts<T>::remove(const T&x,node*&t)
{
    if(t==NULL)return;
    if(x<t->data)remove(x,t->left);
        else if(x>t->data)remove(x,t->right);
            else if(t->left!=NULL&&t->right!=NULL){
                node*tmp=t->right;
                while(tmp->left!=NULL)tmp=tmp->left;
                t->data=tmp->data;
                remove(t->data,t->right);
            }
            else
            {
                node*tmp=t;
                t=(t->left)?t->left:t->right;
                delete tmp;
            }
}

template<class T>
int bts<T>::find_ith(node*t,T&x,int &answer)
{
    if(!t)return answer;
    answer=find_ith(t->left,x,answer);
    x--;
    if(x==0)answer=t->data;
    answer=find_ith(t->right,x,answer);
    return answer;
}

template<class T>
void bts<T>::makeEmpty(node*t)
{
    if(!t)return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

template<class T>
void bts<T>::delsmall(const T&x,node*&t)
{
    if(t==NULL)return;
    if(t->data<x){
        node*tmp=t;
        t=t->right;
        makeEmpty(tmp->left);
        delete tmp;
        delsmall(x,t);
    }
    else delsmall(x,t->left);
}

template<class T>
void bts<T>::delbig(const T&x,node*&t)
{
    if(t==NULL)return;
    if(t->data>x){
        node*tmp=t;
        t=t->left;
        makeEmpty(tmp->right);
        delete tmp;
        delbig(x,t);
    }
    else delbig(x,t->right);
}

template<class T>
void bts<T>::delbs(const T&x,const T&y,node*&t)
{
    if(t==NULL)return;
    if(t->data<=x)delbs(x,y,t->right);
        else if(t->data>=y)delbs(x,y,t->left);
            else
            {
                remove(t->data,t);
                delbs(x,y,t);
            }
}

int main()
{
    bts<int> BTS;
    int n;
    char c[100];
    int x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        if(strcmp(c,"insert")==0){cin>>x;BTS.insert(x);}
            else if(strcmp(c,"find")==0){cin>>x;
                                        if(BTS.find(x))cout<<"Y"<<endl;
                                            else cout<<"N"<<endl;}
                else if(strcmp(c,"delete")==0){cin>>x;BTS.remove(x);}
                    else if(strcmp(c,"delete_less_than")==0){cin>>x;BTS.delsmall(x);}
                        else if(strcmp(c,"delete_greater_than")==0){cin>>x;BTS.delbig(x);}
                             else if(strcmp(c,"delete_interval")==0){cin>>x>>y;BTS.delbs(x,y);}
                                else if(strcmp(c,"find_ith")==0){cin>>x;int ans;ans=BTS.find_ith(x);if(x<=0)cout<<ans<<endl;
                                                                            else cout<<'N'<<endl;}
        strcpy(c,"");
    }
}
