#include<iostream>
#include<cstring>
using namespace std;

template<class elemType>
class linklist
{
   template<class _elemType>friend istream& operator>>(istream&in,linklist<_elemType> &obj);
   template<class _elemType> friend ostream& operator<<(ostream&ou,const linklist<_elemType> &obj);
   template<class _elemType>friend linklist<_elemType> operator+(const linklist<_elemType>l1,const linklist<_elemType>l2);
     private :
     elemType *data;
     int size;
   public :
      linklist(int _size)
      {
       size=_size;
       data=new elemType[size];
      }
      ~linklist()
      {
          delete []data;
      }
};

template<class elemType>
istream& operator>>(istream&in,linklist<elemType> &obj)
{
   for(int i=0;i<obj.size;i++)
   {
       in>>obj.data[i];
   }
   return in;
}

template<class elemType>
ostream& operator<<(ostream&ou,const linklist<elemType> &obj)
{
    for(int i=0;i<obj.size;i++)
    {
        ou<<obj.data[i]<<' ';
    }
    return ou;
}

template<class elemType>
linklist<elemType> operator+(const linklist<elemType>l1,const linklist<elemType>l2)
{
    linklist<elemType> result(l1.size+l2.size);
    for(int i=0;i<l1.size;i++)
        result.data[i]=l1.data[i];
    for(int i=l1.size;i<l1.size+l2.size;i++)
        result.data[i]=l2.data[i-l1.size];
    return result;
}

template<class elemType>
void work(linklist<elemType>l1,linklist<elemType>l2)
{
  cin>>l1>>l2;
  cout<<l1+l2;
}

main()
{
  char s[100]; int n,m;
  cin>>s;
  cin>>n>>m;
  if(strcmp(s,"int")==0){linklist<int>l1(n),l2(m);work(l1,l2);}
  if(strcmp(s,"char")==0){linklist<char>l1(n),l2(m);work(l1,l2);}
  if(strcmp(s,"double")==0){linklist<double>l1(n),l2(m);work(l1,l2);}
  return 0;
}


