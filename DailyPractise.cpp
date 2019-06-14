#include <iostream>
#include <string>
#include <map>
#include <list>
#include <random>
#include "dijkstra.h"
using namespace std;


int main()
{
	Graph    djGarph(3);
	
	djGarph.insert(1, ArcEdge(2, 1));
	djGarph.insert(1, ArcEdge(6, 7));
	djGarph.insert(1, ArcEdge(7, 4));
	djGarph.insert(2, ArcEdge(3, 5));
	djGarph.insert(2, ArcEdge(7, 6));
	djGarph.insert(3, ArcEdge(4, 3));
	djGarph.insert(4, ArcEdge(5, 6));
	djGarph.insert(4, ArcEdge(7, 8));
	djGarph.insert(5, ArcEdge(6, 9));
	djGarph.insert(6, ArcEdge(7, 3));

	vector<int>   arrs(10, 4);
	arrs.resize(20);
	for (auto& n : arrs)
		cout << n << endl;

	cout << djGarph.dijkstra(1, 4);

	return 0;
}