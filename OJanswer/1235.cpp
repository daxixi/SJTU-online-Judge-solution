#include<iostream>
#define noedge 0x7fffffff
using namespace std;

struct edgenode{
        int weight;
        int _begin;
        int _end;
        edgenode*next;
        edgenode(int b,int e,int w,edgenode*n=NULL){
                 _begin=b;
                 _end=e;
                 weight=w;
                 next=n;
                 }
                };

struct vernode{
      edgenode* head;
      vernode(edgenode*h=NULL){
            head=h;}
      };


int main()
{
    int vnum,ednum,startnode,endnode;
    int distance[10010],prev[10010],path[10010];
    bool known[10010];
    for(int i=0;i<10010;i++){distance[i]=noedge;known[i]=false;path[i]=noedge;}
    cin>>vnum>>ednum>>startnode>>endnode;
    vernode *verlist;
    verlist=new vernode[vnum+1];
    int u,v,w;
    for(int i=0;i<ednum;i++)
        {
            cin>>u>>v>>w;
            verlist[u].head=new edgenode(u,v,w,verlist[u].head);
        }
        distance[startnode]=0;prev[startnode]=0;path[startnode]=1;
    for (int i=1;i<=vnum;++i) {
            int min=noedge;
            int uu;
	  for (int j=1;j<=vnum;++j)
	        if (!known[j]&&distance[j]<min){min=distance[j];uu=j;}
            known[uu] = true; //½«u·ÅÈëS
            edgenode *p;
 	   for (p =verlist[uu].head; p!=NULL;p=p->next)
	         if (!known[p->_end]&&((distance[p->_end]>min+p->weight)||(distance[p->_end]==min+p->weight&&path[uu]+1<path[p->_end]))) {
                       distance[p->_end]=min+p->weight;
                       path[p->_end]=path[uu]+1;
                       prev[p->_end]=uu;}
    }
    cout<<distance[endnode]<<endl;
    int ans[10010];int c=0;
    for(int i=endnode;i!=0;i=prev[i])
    {
        ans[c]=i;
        c++;
    }
    for(int i=c-1;i>=0;i--)cout<<ans[i]<<' ';
 }
//||(distance[p->_end]==min+p->weight&&path[uu]+1<path[p->_end])
