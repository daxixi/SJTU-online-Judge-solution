#include<iostream>
#include"A.h"
using namespace std;
int main() {
	Stack s(100);
	for (int i = 0; i < 90; i++) {
		s.push(i);
	}
	Stack s2(s);
    for (int i = 0; i < 90; i++) {
		s.pop();
	}
	cout << s.isEmpty() << endl;
	cout << s2.size0() << endl;
	cout << s2.top()<<endl;
	return 0;
}
