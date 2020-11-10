#include<iostream>
using namespace std;

class hash0{
  private:
      struct node{
      int data;
      int state;
      int num;
      node(){state=0;num=0;}
      };
    node*array;
    int size;
  public:
    hash0(int length=101)
        {
        size=length;
        array=new node[size];
        }
    int find(const int&x)
        {
            int initPos,pos;
            initPos=pos=key(x)%size;
        do {
            if(array[pos].state==0)return -1;
            if(array[pos].state==1&&key(array[pos].data)==key(x))
                return pos;
                pos=(pos+1)%size;
           }while(pos!=initPos);
            return -1;
            }
int insert(const int&x)
        {
            int initPos,pos;
            initPos=pos=key(x)%size;
            do{
                if(array[pos].state!=1){
                array[pos].data=x;
                array[pos].state=1;
                array[pos].num=1;
                return pos;
                }
            if(array[pos].state==1&&key(array[pos].data)==key(x))
            {
                array[pos].num++;
            return pos;
            }
            pos=(pos+1)%size;
                }while(pos!=initPos);
                return -1;
                }
    int key(const int&x){return (x+2000000);}
    int nn(const int&m){return array[m].num; }
};

int main()
{
    int n,a[501],b[501],c[501],d[501];
    cin>>n;
    hash0 h(n*n+10);
    int ans=0;
    for(int i=0;i<n;i++)
         cin>>a[i]>>b[i]>>c[i]>>d[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
               h.insert(a[i]+b[j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int m=h.find(-c[i]-d[j]);
            if(m!=-1)ans+=h.nn(m);}
    cout<<ans;
}
