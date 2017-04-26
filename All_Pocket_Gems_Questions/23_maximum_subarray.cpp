#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int answer = INT_MIN;
		int sum = 0;
		for (int i = 0; i<nums.size(); i++) {
			sum = sum >= 0 ? (sum + nums[i]) : nums[i];
			answer = max(sum, answer);
		}
		return answer;
	}
};

//int main()
//{
//	return 0;
//}