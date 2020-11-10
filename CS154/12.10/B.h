#include<iostream>
using namespace std;
class LongLongInt{
public:
	LongLongInt(const char* str)
	{
      p=0;
      s= new char [100];
      while(str[p]!=0)
      {
          s[p]=str[p];
          p++;
      }
      p--;
	};

	LongLongInt(const LongLongInt& b)
	{
      s=b.s;
      p=b.p;
	};
	~LongLongInt()
	{
	    if(s)delete[]s;
	}
	void plus(const LongLongInt a)
	{
        if(p>a.p)
	    {
	        for(int i=p;i>=p-a.p;i--)
            {
                s[i]=(s[i]-'0'+a.s[i-p+a.p]-'0')+'0';
                while(s[i]>'9')
                {
                    s[i]=s[i]-10;
                    s[i-1]++;
                }
            }
	    }
	}
	void display()
	{
      for(int i=0;i<=p;i++)
        cout<<s[i];
      cout<<endl;
	}
private:
    char *s;
    int p;
};
