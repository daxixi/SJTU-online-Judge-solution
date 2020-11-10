#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

class stack
{
  private:
     struct professor
     {
         int index,num;
         professor(int _index=0,int _num=-1){index=_index;num=_num;}
     }  ;
     int size,top;
     professor *data;
  public:
    stack(int n=0)
    {
        top=-1;
        size=n;
        data=new professor[size];
    }
    ~stack()
    {
        delete []data;
    }
    void enQueue(const int &x,const int &n)
    {
        top++;
        data[top].index=x;data[top].num=n;
    }
    void deQueue()
    {
        top--;
    }
    int topindex()
    {
        return (data[top].index);
    }
      int topnum()
    {
        return (data[top].num);
    }
    bool isEmpty()
    {
        return top==-1;
    }
};
int main()
{
   char tmpname[31];
   char **list;
   list =new char*[500001];
   for(int i=0;i<500001;i++)
      list[i]=new char[31];
   int answer[500001];
   int tmpindex,n;
   cin>>n;
   stack s(n);
   for(int i=0;i<n;i++)
    {
      cin>>tmpindex;
      cin.get();
      cin.getline(tmpname,31);
        strcpy(list[i],tmpname);
    if(s.isEmpty()||s.topindex()>=tmpindex){s.enQueue(tmpindex,i);answer[i]=-1;}
       else
       {
           while(s.topindex()<tmpindex&&!s.isEmpty())
           {
               answer[s.topnum()]=i;
               s.deQueue();
           }
           s.enQueue(tmpindex,i);
           answer[i]=-1;
       }
    }
    for(int i=0;i<n;i++)
        {
            if(answer[i]<0)cout<<-1<<endl;
            else puts(list[answer[i]]);
        }
    for(int i=0;i<500001;i++)
        delete []list[i];
    delete []list;
    return 0;
}
