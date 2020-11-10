#include<iostream>
#include<string>
using namespace std;
void delch(char *p,char c);
int len;
int main()
{
    char c,a[1000];
    cin.getline(a,1000);
    cin>>c;

    delch(a,c);
    cout<<a;
    return 0;
}
void delch(char *p,char c)
{
    while(*p!='\0')
    {
        if(*p=c)
        {
            for(char* i=p;i<=p+len;i++)
                *i=*i+1;
            len--;
            p++;
        }
    }
}
