#pragma once
#pragma once
#ifndef GRAPH
#define GRAPH
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

struct Graph
{	
	vector<pair<int, vector<pair<int, int>>>> adjList;
	void addVertex(int vertex);
	void addEdge(int from, int to, int weight);
	void inputGraph(bool isOriented);
	void printAdjList();
	int findDiameter();
	Graph minimumSpanningTree();
};
#endif