#include<iostream>
#include<vector>
using namespace std;

void find_dulplicate(vector<int>& nums, int range)
{
	bool meet_zero = false;

	for (int i = 0; i<nums.size(); ++i)
	{
		if (nums[i] == 0 || abs(nums[i])>range)
		{
			if (!meet_zero)
				meet_zero = true;
			else
				cout << 0 << endl;
		}
		else if (nums[abs(nums[i])]<0)
		{
			cout << abs(nums[i]) << endl;
		}
		if (nums[abs(nums[i])] != 0)
			nums[abs(nums[i])] *= -1;
		else
			nums[abs(nums[i])] = -1 * (range + 1);
	}
}

// To execute C++, please define "int main()"
//int main() {
//	vector<int> vi = { 2,3,2,0,1,3 };
//	find_dulplicate(vi, 3);
//	return 0;
//}
