#include "common.h"


class Test
{
public:
	static void    fun()
	{
		cout << "test function" << endl;
	}
};

typedef void (*FUNT)();


int main()
{
	int  arrs[10];
	FUNT  foo(Test::fun);
	cout << hex << (unsigned)foo << endl;
	cout << hex << (unsigned)(&Test::fun) << endl;
	foo();
	return 0;	
}