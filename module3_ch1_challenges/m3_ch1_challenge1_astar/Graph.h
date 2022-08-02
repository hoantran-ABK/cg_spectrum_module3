#pragma once
#include <vector>
#include <map>

#include "Node.h"

using namespace std;

class Graph
{
public:
	Graph();
	void AddNode(char letter, map<char,int> adj);
	void AddConnection(char new_x, char new_y, int cost);
	vector<Node> GetNodes();
	map<char, Node> GetAdjList();

private:
	vector<Node> nodes;
	map<char, Node> adj_list;

};

