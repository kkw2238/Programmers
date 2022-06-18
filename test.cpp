#include <iostream>

using namespace std;

class A {
public:
	virtual void f() { cout << "A" << '\n'; }
	virtual void b() { cout << "B" << '\n'; }
};

class B : public A {
public:
	void f() { cout << "C" << '\n'; }
	void b() { cout << "D" << '\n'; }
};

void func(int* a, int* b)
{
	a = b;
	*a = 3;
}

int main()
{
	B test1;
	A* test2 = static_cast<A*>(&test1);

	test1.f();
	test2->f();

	test1.b();
	test2->b();

	int a = 1;
	int b = 2;

	func(&a, &b);

	cout << &a << '\n';
	cout << &b << '\n';

	cout << b << '\n';
}