#include <iostream>
#include <string>
#include <map>
#include <random>
using namespace std;

enum MyEnum
{
	kk,
	tt,
	bb = 10,
	hh 
};


struct A 
{
	char a;
	short c;
	int b;
};



union UStruct
{
	char s[9];
	int n;
	double d;
};


union TestMemory
{
	unsigned int numA;
	int numB;
};


int main(void)
{
	int aa = 10;
	TestMemory  myNum;
	myNum.numB= -100;
	
	
	cout << myNum.numA << endl;
	return 0;
}