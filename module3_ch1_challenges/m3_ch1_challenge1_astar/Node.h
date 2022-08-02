#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node
{
public:
	Node();
	Node(char letter);
	void AddAdjacent(char node, int cost);
	map<char, int> GetAdjacent();
	void PrintAdjacent();
	char GetSymbol();

private:
	char symbol;
	map<char, int> adjacent;

	vector<char> adj;
	vector<int> costs;
};

