#include<iostream>
using namespace std;


struct node{
    node *left,*right;
    int value;
    bool rv;
    node(const int & _value=0,node*_left=NULL,node*_right=NULL)
        {value=_value;left=_left;right=_right;rv=0;}
    node():left(NULL),right(NULL){}
    //~node(){}
    };

class Queue{
        private:
        struct Node{
        Node *next;
        node* data;
        Node(node*&_data,Node* _next=NULL){next=_next;data=_data;}
        Node():next(NULL),data(NULL){}
        };
        Node *front,*rear;
        public:
            Queue()
            {
                front=rear=NULL;
            }
            bool isEmpty(){return (front==NULL);}
            node*dequeue(){
               Node*tmp;
               node*out;
               //cout<<"结点将要出队"<<endl;
               out=front->data;
               tmp=front;//cout<<"标记点1执行成功"<<endl;
               front=front->next;//cout<<"标记点2执行成功"<<endl;
               if(front==NULL)rear=NULL;
               delete tmp;
               return out;
            }
            void enqueue(node* x){
               //cout<<"结点将要入队"<<endl;
               if(!rear){front=rear=new Node(x);}
               else
               {
                   rear=rear->next=new Node(x);
               }
               //cout<<front->data->value;
            }
    };
class Tree{
      friend istream &operator>>(istream &is,Tree & tree);
  private:

    int n,maxtp,_root;
    node*root;
    int *v,*l,*r,*tp;
    Queue Q;
    int max(int x,int y){return (x>y)?x:y;}
    node *create(int &vv);
    void preOrder(node*t)const;
    void postOrder(node*t)const;
  public:
    Tree(const int &_n=0);
    //~Tree();
    void create();
    int qtp(int i);
    void preOrder(){preOrder(root);}
    void postOrder(){postOrder(root);}
    void levelOrder();
};

int Tree::qtp(int i)
{
    if((l[i]==0&&r[i]==0)||(i==0))return 0;
       else return(max(qtp(l[i]),qtp(r[i]))+1);
}

node *Tree::create(int &vv)
{
    node *tmp;
    tmp=new node(v[vv]);
    if(l[vv]!=0)tmp->left=create(l[vv]);
    if(r[vv]!=0)tmp->right=create(r[vv]);
    return tmp;
}

istream &operator>>(istream &is,Tree & tree)
{
   for(int i=1;i<=tree.n;i++)
   {
       is>>tree.l[i]>>tree.r[i]>>tree.v[i];
   }
   for(int i=1;i<=tree.n;i++)
   {
       tree.tp[i]=tree.qtp(i);
       if(tree.tp[i]>tree.maxtp){tree.maxtp=tree.tp[i];tree._root=i;}
   }
   return is;
}

void Tree::create()
{
  root=create(_root);
}

Tree::Tree(const int &_n)
{
  n=_n;
  v=new int[n*2]();
  l=new int[n*2]();
  r=new int[n*2]();
  tp=new int[n*2]();
  maxtp=0;
  _root=0;
}


int main()
{
    int N;
    cin>>N;
    Tree _tree(N);
    cin>>_tree;
    _tree.create();
    _tree.preOrder();
    cout<<endl;
    _tree.postOrder();
    cout<<endl;
    _tree.levelOrder();
    cout<<endl;
    return 0;
}

void Tree::preOrder(node*t)const
{
    if(!t)return;
    cout<<t->value<<' ';
    preOrder(t->left);
    preOrder(t->right);
}
void Tree::postOrder(node*t)const
{
    if(!t)return;
    postOrder(t->left);
    cout<<t->value<<' ';
    postOrder(t->right);
}

void Tree::levelOrder()
{
    Queue Q;
    Q.enqueue(root);
    node *tmp,*_tmp;
    while(!Q.isEmpty())
    {
      tmp=Q.dequeue();
      cout<<tmp->value<<' ';
      _tmp=tmp->right;
      while(_tmp&&!_tmp->rv)
      {
          _tmp->rv=1;
          Q.enqueue(_tmp);
          _tmp=_tmp->right;
      }
      if(tmp->left){
            Q.enqueue(tmp->left);
       _tmp=tmp->left->right;
      while(_tmp&&!_tmp->rv)
      {
          _tmp->rv=1;
          Q.enqueue(_tmp);
          _tmp=_tmp->right;
      }

      }
    }
}
