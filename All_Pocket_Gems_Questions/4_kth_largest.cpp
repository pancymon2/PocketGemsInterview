#include<vector>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return helper(nums, 0, nums.size() - 1, k);
	}
private:

	int helper(vector<int>& nums, int s, int e, int k)
	{
		if (k <= 0 || e - s + 1 < k)
			return INT_MIN;
		int pos = partition(nums, s, e);
		if (pos - s == k - 1)
			return nums[pos];
		else if (pos - s > k - 1)
			return helper(nums, s, pos - 1, k);
		else
			return helper(nums, pos + 1, e, k - pos - 1 + s);
	}

	int partition(vector<int>& nums, int s, int e)
	{
		int pivot = nums[s];
		int j = e;
		int i = s;
		while (i < j)
		{
			while (nums[j] < pivot&&i < j)
				--j;
			if (j > i)
				nums[i++] = nums[j];
			while (nums[i] > pivot&&i < j)
				++i;
			if (j > i)
				nums[j--] = nums[i];
		}
		nums[i] = pivot;
		return i;
	}
};