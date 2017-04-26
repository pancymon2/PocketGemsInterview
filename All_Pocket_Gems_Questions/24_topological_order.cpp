#include<vector>
#include<queue>

using namespace std;

class Solution_2 {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<int> answer;
		vector<vector<int>> adjacent;
		vector<int> indgree(numCourses, 0);
		for (int i = 0; i < numCourses; i++)
		{
			vector<int> vi;
			adjacent.push_back(vi);
		}
		for (int i = 0; i < prerequisites.size(); i++)
		{
			adjacent[prerequisites[i].second].push_back(prerequisites[i].first);
			indgree[prerequisites[i].first]++;
		}
		queue<int> q;
		for (int i = 0; i < indgree.size(); i++)
		{
			if (indgree[i] == 0)
				q.push(i);
		}
		int counter = 0;
		while (!q.empty())
		{
			int vertex = q.front();
			counter++;
			q.pop();
			answer.push_back(vertex);
			for (int i = 0; i < adjacent[vertex].size(); i++)
			{
				//indgree[adjacent[vertex][i]]--;
				if (--indgree[adjacent[vertex][i]] == 0)
					q.push(adjacent[vertex][i]);
			}
		}
		if (counter != numCourses)
			return vector<int>();
		return answer;
	}
};

class Solution_1 {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> adjacent;
		vector<int> indgree(numCourses, 0);
		for (int i = 0; i < numCourses; i++)
		{
			vector<int> vi;
			adjacent.push_back(vi);
		}
		for (int i = 0; i < prerequisites.size(); i++)
		{
			adjacent[prerequisites[i].first].push_back(prerequisites[i].second);
			indgree[prerequisites[i].second]++;
		}
		queue<int> q;
		for (int i = 0; i < indgree.size(); i++)
		{
			if (indgree[i] == 0)
				q.push(i);
		}
		int counter = 0;
		while (!q.empty())
		{
			int vertex = q.front();
			counter++;
			q.pop();
			for (int i = 0; i < adjacent[vertex].size(); i++)
			{
				//indgree[adjacent[vertex][i]]--;
				if (--indgree[adjacent[vertex][i]] == 0)
					q.push(adjacent[vertex][i]);
			}
		}
		if (counter != numCourses)
			return false;
		return true;
	}
};

//int main()
//{
//	return 0;
//}