#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{char c;
char str[80];
void delchar(char *str, char c);
gets(str);
cin>>c;
delchar(str, c);
cout<<(str);}
void delchar(char *str, char c)
{int i, j;i = j = 0;
while(str[i] != '\0')
    {if(str[i] != c){str[j] = str[i];j++;}i++;}str[j] = '\0';}
