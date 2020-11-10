#include<iostream>
#include<cstring>
using namespace std;

class turing
{
   private:
       struct node
       {
           int year;
           char* name;
           node*next;
           node(const int&_year,char*_name,node*_next=NULL){year=_year;name=new char[31];strcpy(name,_name);next=_next;}
           node():next(NULL){}
           ~node(){delete []name;}
       };
       node* head;
   public:
    turing();
    ~turing();
    void _insert(int i_year,char*_name);
    void _delete(const int&i);
    void _list(const int&i);
};

turing::turing()
{
    head=new node;
}

turing::~turing()
{
    node*p,*q;
    p=head->next;
    while(p)
    {
       q=p;
       p=p->next;
       delete q;
    }
}

void turing::_delete(const int&i)
{
    node *p,*q;
    p=head;
    for(int j=0;j<i-1;j++)
        p=p->next;
    q=p->next;
    p->next=p->next->next;
    delete q;
}

void turing::_list(const int&i)
{
   node *p;
   p=head;
   for(int j=0;j<i;j++)
      p=p->next;
   cout<<p->year<<' '<<p->name<<'\n'<<'\r';
}

void turing::_insert( int _year,char*_name)
{
    node *_new;
    node *p;
    p=head;
    while(p->next)
    {
       if(_year<p->next->year)break;
       if((_year==p->next->year)&&(strcmp(_name,p->next->name)<0))break;
       p=p->next;
    }
    _new=new node(_year,_name,p->next);
    p->next=_new;
}
char* getname()
{
    char *tmp,_tmp;
    tmp=new char;
    int i=0;
    cin.get();
    _tmp=cin.get();
    while(_tmp!='\0'&&_tmp!='\n'&&_tmp!='\r')
    {
      tmp[i]=_tmp;
      i++;
      _tmp=cin.get();
    }
    tmp[i]='\0';
    return tmp;
}

main()
{
    turing _list;
    int n,year,position;
    char *ss,*name;
    ss=new char;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ss;
        if(strcmp(ss,"insert")==0){cin>>year;name=new char[31];cin.getline(name,31);_list._insert(year,name);delete []name;}
        if(strcmp(ss,"delete")==0){cin>>position;_list._delete(position);}
        if(strcmp(ss,"list")==0){cin>>position;_list._list(position);}
    }
    delete ss;
    return 0;
}
