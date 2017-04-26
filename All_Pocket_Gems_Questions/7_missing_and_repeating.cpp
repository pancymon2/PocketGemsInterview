#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

vector<int> miss_and_repeat_xor(vector<int>& nums)
{
	vector<int> answer;
	int x = 0;
	int y = 0;

	int n = nums.size();
	int xor1 = 0;
	for (int i = 0; i < n; i++)
	{
		xor1 ^= nums[i];
		xor1 ^= (i + 1);
	}
	int one_bit = xor1&~(xor1 - 1);
	for (int i = 0; i < n; i++)
	{
		if (nums[i] & one_bit)
			x ^= nums[i];
		else
			y ^= nums[i];
		if ((i + 1) & one_bit)
			x ^= (i + 1);
		else
			y ^= (i + 1);
	}
	answer.push_back(x);
	answer.push_back(y);
	return answer;
}

vector<int> miss_and_repeat_abs(vector<int>& nums)
{
	vector<int> answer;
	int miss;
	int repeat;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[abs(nums[i]) - 1]>0)
			nums[abs(nums[i]) - 1] *= -1;
		else
			repeat = abs(nums[i]);
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > 0)
			miss = i + 1;
	}
	answer.push_back(miss);
	answer.push_back(repeat);
	return answer;
}

//int main()
//{
//	vector<int> vi = { 1,2,3,4,5,6,6 };
//	vector<int> answer;
//
//	answer = miss_and_repeat_xor(vi);
//	for (int i = 0; i < answer.size(); i++)
//		cout << answer[i] << endl;
//
//	answer = miss_and_repeat_abs(vi);
//	for (int i = 0; i < answer.size(); i++)
//		cout << answer[i] << endl;
//}