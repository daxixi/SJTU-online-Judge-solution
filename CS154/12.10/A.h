#include<iostream>
using namespace std;
class Stack
{
public:
	bool isEmpty() const //判断是否为空
	{
	if(p==-1)return true;
     return false;
	}

	//出栈
	void pop() //删除栈顶元素
	{
     p--;
	}
	void push(int val) //插入一个元素
	{
	p++;
     a[p]=val;
	}

	int size() const //返回栈元素个数
	{
	 return (p+1);
	}
	// //构造函数
	Stack(int cap=100)
	{
	    n=cap;
        a=new int[n];
	    p=-1;
	}
    //拷贝构造函数
    Stack(const Stack& s)
    {
        n=s.n;
        a=s.a;
        p=s.p;
    }
	//析构
	~Stack()
	{
      if(a)delete[]a;
	}
	//输出栈顶元素
	int top()
	{
    if(!isEmpty())return (a[p]);
	}
private:
    int n,p;
    int *a;
};
