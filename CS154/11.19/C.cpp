#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
char *mystrrchr(char *str, char ch);
int main()
{
    char ch;
    char str[100];
    cin>>str;
    cin>>ch;
    cout<<mystrrchr(str,ch);
        return 0;
}
char *mystrrchr(char *str, char ch)
{
    int j=-1;
    for(int i=0;i<=strlen(str);i++)
        if (str[i]==ch)j=i;
    if(j==-1)return NULL;
        else {
            char *sub=new char[strlen(str)-j+1];
            strncpy(sub,str+j,strlen(str)-j+1);
            return sub;
        };
}
