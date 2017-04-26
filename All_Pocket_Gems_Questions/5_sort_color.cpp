#include<vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int l = 0;
		int r = nums.size() - 1;
		int i = 0;
		while (i <= r)
		{
			if (nums[i] == 0)
				swap(nums[i++], nums[l++]);
			else if (nums[i] == 2)
				swap(nums[i], nums[r--]);
			else
				i++;
		}
	}
private:
	void swap(int &a, int&b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
};