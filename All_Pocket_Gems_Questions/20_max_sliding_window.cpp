#include<vector>
#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> answer;
		deque<int> dq;
		for (int i = 0; i < nums.size(); i++)
		{
			if (!dq.empty() && i - dq.front() >= k)
				dq.pop_front();
			while (!dq.empty() && nums[dq.back()] <= nums[i])
				dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1)
				answer.push_back(nums[dq.front()]);
		}
		return answer;
	}
};
//
//int main()
//{
//	vector<int> vi = { 1 };
//	Solution solution;
//	vector<int> answer = solution.maxSlidingWindow(vi, 1);
//	return 0;
//}