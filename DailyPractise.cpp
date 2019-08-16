#include "common.h"


class Base
{
protected:
	int num = 100;
};

class BaseA : public Base
{
public:
	int getNum()
	{
		return this->num;
	}
};

class BaseB : public BaseA
{
public:
	int getBnum()
	{
		return this->num;
	}
};


int main()
{
	BaseB    testb;
	cout<<testb.getBnum();
	return 0;	
}