#include <iostream>
#include <queue>

#include "Node.h"

vector<char> AStar(map<char, Node>& graph, char start, char end, int h);

vector<char> ReconstructPath(map<char,char> CameFrom, char start, char goal);

int main()
{
	map<char, Node> graph = map<char, Node>();
	Node a = Node('a');
	Node b = Node('b');
	Node c = Node('c');
	Node d = Node('d');
	Node e = Node('e');

	a.AddAdjacent('b', 5);
	b.AddAdjacent('a', 5);

	b.AddAdjacent('c', 1);
	c.AddAdjacent('b', 1);

	a.AddAdjacent('d', 7);
	d.AddAdjacent('a', 7);

	c.AddAdjacent('d', 1);
	d.AddAdjacent('c', 1);

	e.AddAdjacent('a', 2);
	a.AddAdjacent('e', 2);

	e.AddAdjacent('d', 4);
	d.AddAdjacent('e', 4);

	graph['a'] = a;
	graph['b'] = b;
	graph['c'] = c;
	graph['d'] = d;
	graph['e'] = e;

	vector<char> reversedPath = AStar(graph, 'a', 'd', 0);

}

vector<char> AStar(map<char, Node>& graph, char start, char end, int h)
{

	vector<char> OpenList = vector<char>();
	vector<int> Weights = vector<int>();

	map<char, char> CameFrom = map<char, char>();


	map<char, int> gScore = map<char, int>();
	gScore[start] = 0;

	map<char, int> fScore = map<char, int>();
	fScore[start] = h;	// should be heuristic but dont have rn

	OpenList.push_back('a');
	Weights.push_back(0);

	while (!OpenList.empty())
	{
		// Pop out of OpenList the value with the smallest weight as "Current"
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
			return vector<char>();
		}

		char currentNode = OpenList[min_index];
		int currentMinScore = min_value;

		cout << "Visiting (" << currentNode << ")...\n";

		OpenList.erase(OpenList.begin()+min_index);
		Weights.erase(Weights.begin() + min_index);

		// if "Current" is the goal: reconstruct path
		if (currentNode == end)
		{
			cout << "Done... Reconstructing Path Now..." << endl;
			vector<char> reversedPath = ReconstructPath(CameFrom, start, end);
			cout << endl;
			cout << "Total Cost : " << gScore[end];
			return reversedPath;
		}

		// For all neighbors of "Current"
			// tempScore = weight(current -> neighbor) + heuristic()
			// if tempScore < nodeScore[neighbor] (best path to this specific neighbor)
				// cameFrom[neighbor] = current (preceding node for neighbor is the current node)
				// nodeScore[neighbor] = tempScore
				// if neighbor not already in OpenList
					// add it into OpenList to explore later
		Node n = graph[currentNode];
		map<char, int> neighbors = n.GetAdjacent();
		for (map<char,int>::iterator it = neighbors.begin(); it != neighbors.end(); it++)
		{
			// tentative score = (gScore up to currentNode) + (weight from currentNode -> neighbor[i])
			int tentative = gScore[currentNode] + it->second;

			// if gScore not found for a node yet, it should be infinite
			if (gScore.count(it->first) <= 0)
			{
				gScore[it->first] = INT_MAX;
			}

			if (tentative < gScore[it->first])
			{
				CameFrom[it->first] = currentNode;
				gScore[it->first] = tentative;
				fScore[it->first] = tentative + h;
				if (find(OpenList.begin(), OpenList.end(), it->first) == OpenList.end())
				{
					OpenList.push_back(it->first);
					Weights.push_back(tentative);
				}
			}
		}
	}
}

vector<char> ReconstructPath(map<char, char> CameFrom, char start, char goal)
{
	vector<char> reversedPath = vector<char>();
	char current = goal;
	reversedPath.push_back(current);

	while (true)
	{
		char prev = CameFrom[current];
		current = prev;
		reversedPath.push_back(current);

		if (current == start)
		{
			break;
		}
	}

	for (int i = reversedPath.size() - 1; i >= 0; i--)
	{
		cout << reversedPath[i];
	}
	return reversedPath;
}
