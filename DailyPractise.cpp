#pragma warning(disable: 4250)

#include "common.h"
#include <fstream>
#include <regex>

class Base
{
public:
	Base(int intNum) :basePtr(new nestedClass), baseNumber(intNum)
	{
		cout << "constructor Base" << endl;
	}
	Base(): basePtr(new nestedClass), baseNumber(23333)
	{
		cout << "constructor Defalut Base" << endl;
	}
	virtual void Function1()
	{
		cout << "base function1" << endl;
	}
	virtual void Function2()
	{
		cout << "base function2" << endl;
	}

	class nestedClass
	{
	public:
		int number =100;
	}*	basePtr;

	int getNum()
	{
		return baseNumber;
	}
	friend  class friendTest;
private:
	int baseNumber;

};


class DerivedA: virtual public Base	
{
public:
	DerivedA(int BaNum, int DeNum) : Base(DeNum), DeNumber(DeNum)
	{
		cout << "cotr DerivedA" << endl;
	}
	virtual void Function1() override
	{
		cout << "derivedA fun1" << endl;
	}
	//virtual void Function2() override
	//{
	//	cout << "derivedA fun2" << endl;
	//}
private:
	int DeNumber;
};

class DerivedB : virtual public Base
{
public:
	DerivedB(int BaNum, int Denum) : Base(BaNum), selfNumber(Denum)
	{
		cout << "cotr DerivedB" << endl;
	}
	//virtual void Function1() override
	//{
	//	cout << "derivedB fun1" << endl;
	//}
	virtual void Function2() override
	{
		cout << " derivedB fun2" << endl;
	}
private:
	int selfNumber;
};


class CompoundDerivedAndBase : public DerivedA, public DerivedB
{
public:
	CompoundDerivedAndBase(const DerivedA& DeA, const DerivedB& Deb): DerivedA(DeA), DerivedB(Deb), FinalNumber(8888)
	{
		cout << "cotr1 CompoundDerivedAndBase" << endl;
	}
	CompoundDerivedAndBase(int a, int b, int c, int d) :DerivedA(a, b), DerivedB(c, d), Base(66666655)
	{
		cout << "cotr2 CompoundDerivedAndBase" << endl;
	}

private:
	int FinalNumber;

};





typedef void(*FunPtr)();

int main()
{
	string  target = "subject";
	std::regex   reg("sub");

	smatch  arrs;
	if (std::regex_search(target, arrs, reg))
	{
		for (int index = 0; index < arrs.size(); ++index)
		{
			cout << "匹配： "<<arrs[index] << endl;
		}
	}
	cout << endl;

	//if (std::regex_match("subject", std::regex("(sub)(.*)")))
	//	std::cout << "string literal matched\n";

	//const char cstr[] = "subject";
	//std::string s("subject");
	//std::regex e("(sub)(.*)");

	//if (std::regex_match(s, e))
	//	std::cout << "string object matched\n";

	//if (std::regex_match(s.begin(), s.end(), e))
	//	std::cout << "range matched\n";


	//std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
	//std::regex_match(s, sm, e);
	//std::cout << "string object with " << sm.size() << " matches\n";



	//std::cout << "the matches were: ";
	//for (unsigned i = 0; i < sm.size(); ++i) {
	//	std::cout << "[" << sm[i] << "] ";
	//}




	return 0;

}





