#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution_2_sum {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> index;
		vector<int> answer;
		for (int i = 0; i < nums.size(); i++)
		{
			int complement = target - nums[i];
			if (index.count(complement))
			{
				answer.push_back(index[complement]);
				answer.push_back(i);
				return answer;
			}
			else
				index[nums[i]] = i;
		}
		return answer;
	}
};

class Solution_3_sum {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> answer;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int sum = 0 - nums[i];
			for (int j = i + 1, k = nums.size() - 1; j < k;)
			{
				if (nums[j] + nums[k] == sum)
				{
					vector<int> tmp = { nums[i], nums[j], nums[k] };
					answer.push_back(tmp);
					while (j < nums.size() - 1 && nums[j] == nums[j + 1])
						++j;
					++j;
					while (k > j + 2 && nums[k] == nums[k - 1])
						--k;
					--k;
				}
				else if (nums[j] + nums[k] < sum)
					++j;
				else
					--k;
			}
		}

		return answer;
	}
};

class Solution_3_sum_closest {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ans = nums[0] + nums[1] + nums[2], len = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i<len - 2; i++) {
			int sum = target - nums[i];
			int lo = i + 1, hi = len - 1;
			while (lo<hi) {
				int cur = nums[lo] + nums[hi];
				if (abs(nums[i] + cur - target)<abs(ans - target))ans = nums[i] + cur;
				if (cur<sum)lo++;
				else if (cur>sum)hi--;
				else return target;
			}
		}
		return ans;
	}
};

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		if (nums.size() == 0) {
			return ans;
		}
		sort(nums.begin(), nums.end(), less<int>());
		return nSum(4, 0, target, nums);
	}
	vector<vector<int>> nSum(int k, int index, int target, vector<int>& nums) {
		vector<vector<int>> ans;
		if (index >= nums.size()) {
			return ans;
		}
		if (k == 2) {
			for (int i = index, j = nums.size() - 1; i < j;) {
				int sum = nums[i] + nums[j];
				if (sum == target) {
					ans.push_back(vector<int>{nums[i], nums[j]});
					while (i < j && nums[i] == nums[i + 1]) {
						++i;
					}
					while (i < j && nums[j] == nums[j - 1]) {
						--j;
					}
					++i, --j;
				}
				else if (sum < target) {
					++i;
				}
				else {
					--j;
				}
			}
			return ans;
		}
		for (int i = index; i < nums.size(); ++i) {
			vector<vector<int>> tmp = nSum(k - 1, i + 1, target - nums[i], nums);
			for (auto j : tmp) {
				j.insert(j.begin(), nums[i]);
				ans.push_back(j);
			}
			while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
				++i;
			}
		}
		return ans;
	}
};

//int main()
//{
//	//Solution solution;
//	//vector<int> vi = { -1,-1,2 };
//	//vector<vector<int>> answer = solution.threeSum(vi);
//	return 0;
//}