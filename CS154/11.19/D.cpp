#include<iostream>
using namespace std;
int main()
{    char s[10000],kk[10];
    cin>>kk;
    cin>>s;
    int i=0,l,ans=0;
    int a=0,b=0;
    while((s[i]>='0')&&s[i]<='9')
    {
        a=a*10+s[i]-'0';
        i++;
    }
    if(s[i]=='+')l=1;
    if(s[i]=='-')l=2;
    if(s[i]=='*')l=3;
    if(s[i]=='/')l=4;
    i++;
    while((s[i]>='0')&&s[i]<='9')
    {
        b=b*10+s[i]-'0';
        i++;
    }
       switch(l)
    {
        case 1:ans=a+b;break;
        case 2:ans=a-b;break;
        case 3:ans=a*b;break;
        case 4:ans=a/b;break;
    }
    cout<<ans;
    return 0;
}
