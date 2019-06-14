#pragma once
#include <iostream>
#include <list>
#include <vector>

using namespace std;




struct ArcEdge
{
public:
	int number;
	int weight;
	//ArcEdge* next;

	bool operator==(const ArcEdge& rhs) const
	{
		if (this->number == rhs.number)
		{
			return true;
		}
		else
			false;
	}
	ArcEdge(const int num, const int wei) :number(num), weight(wei) {};
};

struct Node
{
	//int			number;
	ArcEdge* firstArc;
};

class Graph
{
public:
	Graph(const int size = 10) : _nodeSize(size)
	{
		_GraphData.resize(size);
	}
	//double 
	bool insert(const int vertexNode, const ArcEdge& insertEdge )
	{
		if (_nodeSize <= vertexNode  )
		{
			_GraphData.resize(int(vertexNode*1.5));
			_nodeSize = int(vertexNode*1.5);
			cout << "use ";
		}
		auto&  fistArcEdge = _GraphData[vertexNode];
		auto ptr = std::find(fistArcEdge.begin(), fistArcEdge.end(), insertEdge);
		auto itr = fistArcEdge.end();
		if (ptr == fistArcEdge.end())
		{
			fistArcEdge.push_back(insertEdge);
		}
		else
		{
			return false;
		}
		//double direction edge
		if (_nodeSize <= insertEdge.number)
		{
			_GraphData.resize(int (insertEdge.number*1.5));
			_nodeSize = int(insertEdge.number*1.5);
		}
		fistArcEdge = _GraphData[insertEdge.number];
		ArcEdge   tempVal(vertexNode, insertEdge.weight);
		ptr = std::find(fistArcEdge.begin(), fistArcEdge.end(), tempVal);
		if (ptr == fistArcEdge.end())
		{
			fistArcEdge.push_back(tempVal);
		}
		else
		{
			return false;
		}

		return true;
	}


	int dijkstra(const int srcNode, const int dstNode) const
	{
		vector<int>   distance(_nodeSize, INT_MAX);
		vector<bool>	exist(_nodeSize, false);
		distance[srcNode] = 0;
		exist[srcNode] = true;
		int head = srcNode;
		while (exist[dstNode] != true)
		{
			auto  fistArc = _GraphData[head];
			for (auto ptr = fistArc.begin(); ptr != fistArc.end(); ptr++)
			{
				int ptrNodeNum = ptr->number;
				if (exist[ptrNodeNum] != true && distance[ptrNodeNum] > (distance[head] + ptr->weight))
				{
					distance[ptrNodeNum] = (distance[head] + ptr->weight);
				}
			}
			//find the minest number in distance
			int minPostion = 1;
			//if (srcNode == minPostion)
			//{
			//	minPostion = 2;
			//}
			int compareNum = INT_MAX;
			for (int index = 1; index < distance.size(); index++)
			{
				if (index != head && distance[index] < compareNum)
				{
					minPostion = index;
					compareNum = distance[index];
				}
			}
			exist[minPostion] = true;
			head = minPostion;
		}
		return distance[dstNode];
	}


private:
	int						_nodeSize;
	vector<list<ArcEdge>>	_GraphData;
};



