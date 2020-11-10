#include<iostream>
#include<string.h>
using namespace std;
int minlen(char *str[], int n);
int main()
{

    int n;
    cin>>n;
    char **str;
    str= new char *[n];
    for(int i=0;i<n;i++){str[i]=new char[30];cin>>str[i];}
    cout<<minlen(str,n);
    for(int i=0;i<n;i++)delete []str[i];
    delete[] str;
    return 0;
}
int minlen(char *str[], int n)
{
   int i=strlen(str[0]);
   for(int j=0;j<n;j++)
   if(strlen(str[j])<i)i=strlen(str[j]);
   return i;
}
