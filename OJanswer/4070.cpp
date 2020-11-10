#include<iostream>
using namespace std;
#include<cstring>
#include<stdio.h>

int divide(char a[31][31],int low,int high)
{
    char k[31];
    strcpy(k,a[low]);
    do{while(low<high&&strcmp(a[high],k)>=0)high--;
        if(low<high){strcpy(a[low],a[high]);++low; }
        while(low<high&&strcmp(a[low],k)<=0)low++;
        if(low<high){strcpy(a[high],a[low]);--high;}
    }while(low!=high);
    strcpy(a[low],k);
    return low;
}
void quickSort(char a[31][31],int low,int high)
{
    int mid;
    if(low>=high)return;
    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}
int main()
{
    char ch[31][31];
    char c,cc[31];
    c=cin.get();
    cin.get();
    int i=0,l,p;
    while(true)
    {
        strcpy(ch[i],"");
        int t=0;
        ch[i][0]=getchar();
        while(ch[i][t]&&ch[i][t]!='\n'&&ch[i][t]!='\0'&&ch[i][t]!='\r')
            {
                t++;
            ch[i][t]=getchar();
            }ch[i][t]='\0';
        if(strcmp(ch[i],"@")==0)break;
        l=strlen(ch[i]);
        for(int j=0;j<l;j++)
            {
            l=strlen(ch[i]);
            if(ch[i][j]==c)
                {
                    for(int k=j;k<l-1;k++)
                        ch[i][k]=ch[i][k+1];
                    ch[i][l-1]='\0';
                    j--;
                }
            }
        i++;
    }
    quickSort(ch,0,i-1);
    for(int j=i-1;j>=0;j--)
        puts(ch[j]);
}
