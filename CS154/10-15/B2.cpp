#include<iostream>
using namespace std;
int main()
{
    char a,b;
    cin>>a;
    b=a-'a'+1;
    if(b==1||b==5||b==9||b==15||b==21)
        cout<<"Ԫ��";
        else if((b>=1)&&(b<=26))
          cout<<"����";
            else cout<<"�Ƿ�����";
            return 0;
}
