// shared_ptr::reset example


#include "pch.h"
#include <iostream>
#include <memory>

using namespace std;
class FooClass
{
public:
	FooClass(int number)
	{
		m_Number = number;
		cout << "constructor" << endl;
	}
	FooClass(const FooClass& rhs)
	{
		this->m_Number = rhs.m_Number;
		cout << "copy constructor" << endl;
	}
	~FooClass()
	{
		cout << "deconstructor" << endl;
	}
	void PrintNum()
	{
		cout << this->m_Number << endl;
	}
protected:
private:
	int m_Number;
};

int main() {
	std::shared_ptr<FooClass> sp(new FooClass(4));
	std::shared_ptr<FooClass> sp1 = sp;

	sp.reset();

	sp1->PrintNum();


	return 0;
}