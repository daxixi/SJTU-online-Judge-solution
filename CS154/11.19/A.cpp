#include<iostream>
#include<cstring>
using namespace std;
char city[30][30];
void qsort(int l,int r);
int main()
{
    int i=0;
    cin>>city[i];
    while(city[i][0]!='@')
    {
        i++;
        cin>>city[i];
    }
     qsort(0,i-1);
    for(int j=0;j<i;j++)
        cout<<city[j]<<endl;
    return 0;
}
void qsort(int l,int r)
{
    char* mid=city[(l+r)/2];
    char* str;
    int i,j;
    i=l;j=r;
    do{
    while ((strcmp(city[i],mid))<0)i++;
    while  ((strcmp(city[j],mid))>0)j--;
    if(i<=j)
    {
       string temp_a(city[i]);
       string temp_b(city[j]);
       strcpy(city[i],temp_b.c_str());
       strcpy(city[j],temp_a.c_str());
        i++;
        j--;
    }
    }while(i<=j);
    if(l<j)qsort(l,j);
    if(i<r)qsort(i,r);
}
