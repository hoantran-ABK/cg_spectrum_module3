#include "Node.h"

using namespace std;

Node::Node()
{
}

Node::Node(char letter)
	: symbol(letter),
	adjacent(map<char, int>())
{
}

void Node::AddAdjacent(char node, int cost)
{
	this->adjacent[node] = cost;

	this->adj.push_back(node);
	this->costs.push_back(cost);
}

map<char, int> Node::GetAdjacent()
{
	return this->adjacent;
}

void Node::PrintAdjacent()
{
	for (map<char, int>::iterator it = adjacent.begin(); it != adjacent.end(); it++)
	{
		cout << "(" << it->first << "," << it->second << "), ";
	}
}

char Node::GetSymbol()
{
	return this->symbol;
}
