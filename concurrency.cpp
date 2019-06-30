#pragma once 
#include "common.h"
#include <thread>
#include <memory>


struct moveTest
{
	moveTest(int n) : _num(n) {};
	int _num;
};


void hello(char* str)
{
	cout << str << endl;
}

void changeNumber(unique_ptr<moveTest> mo)
{
	mo->_num += 100;
	cout << mo->_num << endl;
}


class Func
{
public:
	Func(int& i) : _i(i) {};
	void operator() ()
	{
		for (int i = 0; i < 5000; i++)
		{
			cout << i << "  ";
		}
	}

private:

	int& _i;

};


int main()
{
	int someLocalState = 111;
	unique_ptr<moveTest>  myMove(new moveTest(someLocalState) );
	unique_ptr<moveTest>   foo = std::move(myMove);
	thread  myTheard(changeNumber, std::move(foo));
	
	if (myTheard.joinable())
	{
		myTheard.join();
		cout << " mythread is joined" << endl;
	}
	return 0;
}