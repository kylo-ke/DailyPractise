#include "common.h"


class Base
{
public:
	class nestedClass
	{
	public:
		int number =100;
	}*	basePtr;

	int name;
	int getNum()
	{
		return basePtr->number;
	}
	Base() :basePtr(new nestedClass)
	{

	}
	friend  class friendTest;
private:
	int keyNum = 999;

};


class friendTest
{
public:
	int getBaseNum()
	{
		return baseCon.keyNum;
	}
	Base   baseCon;
};


int main()
{
	friendTest  fooClass;
	cout << fooClass.getBaseNum();
	return 0;
}


