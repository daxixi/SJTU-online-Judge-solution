#include"B.h"
#include<iostream>
using namespace std;
int main() {
	LongLongInt a("1234567890987654321");
	LongLongInt b("1234567");
	a.display();
	b.display();
	a.plus(b);
	a.display();
	return 0;
}
