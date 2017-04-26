#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution_DFS {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node)
			return node;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
		return helper(node, visited);
	}
private:
	UndirectedGraphNode *helper(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& visited)
	{
		if (visited.count(node))
			return visited[node];

		UndirectedGraphNode* ret = new UndirectedGraphNode(node->label);
		visited[node] = ret;

		for (int i = 0; i < node->neighbors.size(); i++)
		{
				ret->neighbors.push_back(helper(node->neighbors[i], visited));
		}

		return ret;
	}
};

class Solution_BFS {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node)
			return node;

		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
		visited[node] = new UndirectedGraphNode(node->label);

		queue<UndirectedGraphNode*> q;
		q.push(node);

		while (!q.empty())
		{
			UndirectedGraphNode* front = q.front();
			q.pop();


			for (auto nbr:front->neighbors)
			{
				if (visited.count(nbr))
					visited[front]->neighbors.push_back(visited[nbr]);
				else
				{
					UndirectedGraphNode* new_node = new UndirectedGraphNode(nbr->label);
					visited[nbr] = new_node;
					visited[front]->neighbors.push_back(new_node);
					q.push(nbr);
				}

			}
		}
		return visited[node];
	}

};


//int main()
//{
//	Solution solution;
//	UndirectedGraphNode* node0 = new UndirectedGraphNode(0);
//	UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
//	UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
//
//	node0->neighbors.push_back(node1);
//	node1->neighbors.push_back(node2);
//	node2->neighbors.push_back(node2);
//	
//	UndirectedGraphNode* clone = solution.cloneGraph(node0);
//	return 0;
//}