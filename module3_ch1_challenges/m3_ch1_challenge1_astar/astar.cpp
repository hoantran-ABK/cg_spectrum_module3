#include <iostream>
#include <queue>

#include "Graph.h"
#include "Node.h"

void AStar(map<char, Node>& graph, char start, char end, int h);

void AddConnection(map<char, Node>& graph, char new_x, char new_y, int cost);

void PrintGraph(map<char, vector<pair<char,int>>> graph);

void ReconstructPath(map<char,char> CameFrom, char start, char goal);

class NodeComparison 
{
	bool operator() (pair<char,int> lhs, pair<char,int> rhs)
	{
		return false;
	}
};

int main()
{
	map<char, vector<pair<char, int>>> graph;
	graph['a'] = vector<pair<char, int>>();
	graph['b'] = vector<pair<char, int>>();
	graph['c'] = vector<pair<char, int>>();
	graph['d'] = vector<pair<char, int>>();

	graph['a'].push_back(make_pair('b', 5));
	graph['b'].push_back(make_pair('a', 5));

	graph['b'].push_back(make_pair('c', 1));
	graph['c'].push_back(make_pair('b', 1));

	graph['a'].push_back(make_pair('d', 7));
	graph['d'].push_back(make_pair('a', 7));

	graph['c'].push_back(make_pair('d', 1));
	graph['d'].push_back(make_pair('c', 1));

	PrintGraph(graph);


}

void AStar(map<char, Node>& graph, char start, char end, int h)
{

	vector<char> OpenList = vector<char>();
	vector<int> Weights = vector<int>();

	map<char, char> CameFrom = map<char, char>();

	//vector<char> ClosedList = vector<char>();

	map<char, int> gScore = map<char, int>();
	gScore[start] = 0;

	map<char, int> fScore = map<char, int>();
	fScore[start] = 0;	// should be heuristic but dont have rn

	OpenList.push_back('a');
	Weights.push_back(0);

	while (!OpenList.empty())
	{
		// Pop out of OpenList the value with the samllest weight as "Current"
		int min_value = INT_MAX;
		int min_index = -1;
		for (int i = 0; i < OpenList.size(); i++) 
		{
			if (Weights[i] < min_value)
			{
				min_index = i;
				min_value = Weights[i];
			}
		}

		// OpenList is Empty so all paths have been exhausted but no solution found
		if (min_index == -1)
		{
			cout << "No path found..." << endl;
			return;
		}

		char currentNode = OpenList[min_index];
		int currentMinScore = min_value;

		OpenList.erase(OpenList.begin()+min_index);
		Weights.erase(Weights.begin() + min_index);

		// if "Current" is the goal: reconstruct path
		if (currentNode == end)
		{
			ReconstructPath(CameFrom, start, end);
			return;
		}

		// For all neighbors of "Current"
			// tempScore = weight(current -> neighbor) + heuristic()
			// if tempScore < nodeScore[neighbor] (best path to this specific neighbor)
				// cameFrom[neighbor] = current (preceding node for neighbor is the current node)
				// nodeScore[neighbor] = tempScore
				// if neighbor not already in OpenList
					// add it into OpenList to explore later
		graph[currentNode];
	}
}


void AddConnection(map<char, Node> & graph, char new_x, char new_y, int cost)
{
	graph[new_x].AddAdjacent(new_y, cost);
	graph[new_y].AddAdjacent(new_x, cost);
}

void PrintGraph(map<char, vector<pair<char,int>>> graph)
{
	for (map<char, vector<pair<char, int>>>::iterator it = graph.begin(); it != graph.end(); it++)
	{
		cout << "Source " << it->first << ": ";
		for (int i = 0; i < it->second.size(); i++)
		{
			cout << "(" << it->second[i].first << "," << it->second[i].second << "), ";
		}
		cout << endl;
	}
}
