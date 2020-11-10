#include<iostream>
using namespace std;
int main()
{
    char a[100];
    int flag,x,i;
    cin.getline(a,100);
    if(a[0]=='0')
    {
        if(a[1]=='x')flag=16;
        else flag=8;
    }
    else flag=10;
    if(flag==10)cout<<a<<endl;
       else if(flag==8)
       {
           x=a[1]-'0';
           i=1;
           while(a[i+1]!='\0')
           {
               x=(a[i+1]-'0')+x*8;
               i++;
           }
           cout<<x<<endl;
       }
             else
             {
                x=0;
                i=1;
             while(a[i+1]!='\0')
             {
                 if((a[i+1]>='A')&&(a[i+1]<='F'))
                    {
                      x=a[i+1]-'A'+10+x*16;
                      i++;
                    }
                 else
                    {x=a[i+1]-'0'+x*16;
                     i++;}
             }
             cout<<x<<endl;
             }
             return 0;
}
