#include<iostream>
using namespace std;
class Stack
{
public:
	bool isEmpty() const //�ж��Ƿ�Ϊ��
	{
	if(p==-1)return true;
     return false;
	}

	//��ջ
	void pop() //ɾ��ջ��Ԫ��
	{
     p--;
	}
	void push(int val) //����һ��Ԫ��
	{
	p++;
     a[p]=val;
	}

	int size() const //����ջԪ�ظ���
	{
	 return (p+1);
	}
	// //���캯��
	Stack(int cap=100)
	{
	    n=cap;
        a=new int[n];
	    p=-1;
	}
    //�������캯��
    Stack(const Stack& s)
    {
        n=s.n;
        a=s.a;
        p=s.p;
    }
	//����
	~Stack()
	{
      if(a)delete[]a;
	}
	//���ջ��Ԫ��
	int top()
	{
    if(!isEmpty())return (a[p]);
	}
private:
    int n,p;
    int *a;
};
