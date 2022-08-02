#include "Graph.h"

Graph::Graph()
{
}

void Graph::AddNode(char letter, map<char, int> adj)
{
	Node n = Node(letter);
	adj_list[letter] = n;
	this->nodes.push_back(n);

	for (map<char, int>::iterator it = adj.begin(); it != adj.end(); it++)
	{
		n.AddAdjacent(it->first, it->second);
		adj_list[it->first].AddAdjacent(n.GetSymbol(), it->second);
	}


}

void Graph::AddConnection(char new_x, char new_y, int cost)
{
	adj_list[new_x].AddAdjacent(new_y, cost);
	adj_list[new_y].AddAdjacent(new_x, cost);
}

vector<Node> Graph::GetNodes()
{
	return this->nodes;
}

map<char, Node> Graph::GetAdjList()
{
	return this->adj_list;
}
