#include<iostream>
using namespace std;
int factorial(int x)
{
  int result=1;
  if(x<0)throw("n should be greater than zero");
  for(int i=1;i<=x;i++)
  {
    if(result*i<result)throw("n is too large");
    result*=i;
  }
  return result;
}
int main() {
	int x;
	while (cin >> x) {
		try {
			cout << factorial(x) << endl;
		}
		catch (const char *err) {
			cout << err << endl;
		}
	}
	return 0;
}
