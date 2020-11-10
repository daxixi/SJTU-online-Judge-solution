#include<iostream>
#include<cstring>
using namespace std;
bool pp;
struct student{
  int num;
  char name[20];
  char sex[6];
  int age;
  int class0;
  int english;
  int maths;
  int physics;
  int score ;
  int rank0;
};
struct node{
  student data;
  node *next;
};
void print(node* head);
node* addStudent(node* head, node* p) ;
node* insStudent(node* head, node* p);
node* delStudent(node* head, int sno);
 int rmLastStudent(node* head) ;
int main()
{
  int n;
  char ch[10];
  cin>>n;
  node *head;
  head=NULL;
   int j=1;
   while(j<=n)
   {
   cin>>ch;
    if (strcmp(ch,"add")==0)
      {
       node *p=new node();
       p->next=NULL;
      cin>>p->data.num>>p->data.name>>p->data.sex>>p->data.age>>p->data.class0>>p->data.english>>p->data.maths>>p->data.physics;
        p->data.score=p->data.maths+p->data.english+p->data.physics;
        p->data.rank0=1;
        head=addStudent(head, p);j++;}
      else
       if(strcmp(ch,"print")==0) {pp=false; print(head);j++;if(!pp)cout<<"empty";}
       else
       if(strcmp(ch,"del")==0){
                                int sno;
                                cin>>sno;
                                head=delStudent(head,sno);
                                j++;
                               }
       else
       if(strcmp(ch,"rmL")==0){head=delStudent(head,rmLastStudent(head));j++;}
   }
  return 0;
}
node* addStudent(node* head, node* p)
{

   if(head==NULL)
   return p;
    if(head->data.score>p->data.score)p->data.rank0++;
       else if(head->data.score<p->data.score)head->data.rank0++;
   head->next=addStudent(head->next,p);
   return head;
}
node* insStudent(node* head, node* p)
{
      node *p0=new node();
   p0=head;
   while(p0!=NULL)
   {
    if(p0->data.score>p->data.score)p->data.rank0++;
       else if(p0->data.score<p->data.score)p0->data.rank0++;
   p0=p0->next;
   }
    p->next=head;
    return p;
}
void print( node* head)
{
      if(head!=NULL)
       {cout<<"00"<<head->data.num<<' '<<head->data.name<<' '<<head->data.sex<<' '<<head->data.age<<' '<<head->data.class0<<' '<<head->data.english<<' '<<head->data.maths<<' '<<head->data.physics<<' '<<head->data.score<<' '<<head->data.rank0<<endl;
              pp=true;
               print(head->next);}
}
node* delStudent(node* head, int sno)
{
    if(head->data.num==sno)return (head->next);
    else head->next=delStudent(head->next,sno);
    return (head);
}
int rmLastStudent(node* head)
{
   int s=0;int t=0;
   while(head!=NULL)
   {
       if(s<head->data.rank0){s=head->data.rank0;t=head->data.num;}
       head=head->next;
   }
   return t;
}
