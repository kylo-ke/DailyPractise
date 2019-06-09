#include <iostream>
#include <string>
#include <map>
#include <random>
using namespace std;

int main()
{
	std::random_device rd;
	std::map<int, int> hist;
	std::uniform_int_distribution<int> dist(0, 100);

	cout << dist(rd) << endl;
	cout << dist(rd) << endl;
	cout << dist(rd) << endl;

	return 0;
}