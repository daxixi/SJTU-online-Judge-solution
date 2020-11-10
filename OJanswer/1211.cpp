#include<iostream>
#include<cmath>
using namespace std;

class BT{
   friend bool isCBT(const BT&tree);
   private:
       int *data;
       int height;
   public:
    BT(int _height=0);
    void insert(const int &p,const int &x);
    ~BT();
    };
BT::BT(int _height)
    {
      height=_height;
      int n;
      n=pow(2,height)-1;
      data=new int[n];
    }
BT::~BT()
{
    delete[]data;
}
void BT::insert(const int &p,const int &x)
{
   data[p-1]=x;
}
int max(int &x,int &y)
{
    return((x>y)?x:y);
}

//一个队列辅助生成满二叉树
class queue{
   private:
       int* data;
       int length,front,rear;
   public:
       queue(int _length=0){length=pow(2,_length)-1;
                             data=new int[length*100];
                             front=rear=0;
                             }
      ~queue(){delete[]data;}
       void enqueue(const int &x){data[rear]=x;rear++;}
       int  dequeue(){int x=data[front];front++;return x;}
};
int qtp(int i,int *tp,int *l,int *r)
{
    if(l[i]==0&&r[i]==0)return 0;
      else return(max(qtp(l[i],tp,l,r),qtp(r[i],tp,l,r))+1);
}
int main()
{

    int *tp,*l,*r;
    tp=new int[1000000];
    r=new int[1000000];
    l=new int[1000000];
    for(int i=0;i<1000000;i++)tp[i]=0;
    int n,p,q,stop=0,root=0,maxtp=0,num,tmp;
    cin>>n;
    for(int i=1;i<n+1;i++)
    {
      cin>>p>>q;
      if(p==0&&q!=0){cout<<'N'<<endl;return 0;}
      /*if(p!=0&&q==0){stop++;if(stop>1){cout<<'N'<<endl;return 0;}}*/
      l[i]=p;r[i]=q;
      /*if(p==0&&q==0)tp[i]=0;
            else tp[i]=max(tp[p],tp[q])+1;
      if (tp[i]>maxtp){maxtp=tp[i];root=i;}*/
   }
    for(int i=1;i<n+1;i++)
    {tp[i]=qtp(i,tp,l,r);
      if(tp[i]>maxtp){maxtp=tp[i];root=i;}
    }
    num=1;maxtp++;
    BT FBT(maxtp);queue Q(maxtp);
    Q.enqueue(root);
    while(num<pow(2,maxtp))
    {
       tmp=Q.dequeue();
       if(tmp!=0){Q.enqueue(l[tmp]);Q.enqueue(r[tmp]);}
       FBT.insert(num,tmp);
       num++;
    }
    if(isCBT(FBT))cout<<'Y'<<endl;
      else cout<<'N'<<endl;
    delete []tp;
    delete []r;
    delete []l;
    return 0;
}

bool isCBT(const BT&tree)
{
   bool TS=1;
   for(int i=1;i<=tree.height;i++)
   {
      for(int j=1;j<=pow(2,i-1);j++)
       {
           int p;
           p=pow(2,i-1)-1+j;
           if(tree.data[p]==0)TS=0;
              else if(TS==0)return 0;
       }
   }
   return 1;
}
