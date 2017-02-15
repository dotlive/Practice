#include <iostream>
using namespace std;

class Base
{
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};

typedef void(*Fun)();

int main()
{
	Base b;
	Fun pFun = NULL;

	cout << "虚函数表地址: " << (int*)(&b) << endl;
	cout << "虚函数表第一个函数地址: " << (int*)*(int*)(&b) <<endl;	

	pFun = (Fun)*((int*)*(int*)(&b)+0);
	pFun();

	int ** pVtab = (int**)&b;
	pFun = (Fun)pVtab[0][0];
	pFun();

	return 0;
}
