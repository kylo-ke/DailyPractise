#pragma once
#include <iostream>
using namespace std;

class A
{
public:
	A(int size) : m_a_size(size)
	{
		m_a = new int[size];
	}
	 virtual ~A();
private:
	int *m_a;
	int m_a_size;
};

A::~A()
{
	cout << "delete m_a" << endl;
	delete[]m_a;
}

class B : public A
{
public:
	B(int a_size, int b_size) : A(a_size), m_b_size(b_size)
	{
		m_b = new int[b_size];
	}
	~B();
private:
	int *m_b;
	int m_b_size;
};

B::~B()
{
	cout << "delete m_b" << endl;
	delete[]m_b;
}

