#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
    char c,ch;
    int n;int a,b;
    scanf("%d",&n);
    int *data;
    data=new int[n+1]();
    int p=0,max=0;
    while(true)
    {
        int t=0;
        c=getchar();ch=c;
        while(ch!=' '&&ch!='\n'&&ch!='\0'&&ch!='\r'){ch=getchar();}
        if(c=='f')return 0;
            else if(c=='q'){printf("%d%c%d%c",p,' ',max,'\n');}
                else if(c=='a'){scanf("%d%d",&a,&b);data[b]++;if(data[b]>max||(data[b]==max&&b<p)){p=b;max=data[b];}}
    }
}
