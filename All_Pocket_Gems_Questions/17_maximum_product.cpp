#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution_DP {
public:
	int maxProduct(vector<int>& nums) {
		int ret = nums[0];
		int maxp = nums[0];
		int minp = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int tmpmax = maxp;
			int tmpmin = minp;
			maxp = max(max(tmpmax*nums[i], tmpmin*nums[i]), nums[i]);
			minp = min(min(tmpmax*nums[i], tmpmin*nums[i]), nums[i]);
			ret = max(ret, maxp);
		}
		return ret;
	}
};

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int l = 0;
		int cur = 0;
		int ret = INT_MAX;
		for (int r=0; r < nums.size(); r++)
		{
			cur += nums[r];
			if (cur>=s)
			{
				while (cur - nums[l] >= s&&l < r)
				{
					cur -= nums[l++];
				}
				if (ret > r - l + 1)
					ret = r - l + 1;
			}
		}
		return ret == INT_MAX ? 0 : ret;
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> vi = { 1,4,4 };
//	cout << solution.minSubArrayLen(4, vi);
//	return 0;
//}