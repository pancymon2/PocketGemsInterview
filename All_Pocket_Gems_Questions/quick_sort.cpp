#include<vector>
#include<iostream>
using namespace std;

int partition(vector<int>& nums, int s, int e)
{
	int pivot = nums[s];
	int j = e;
	int i = s;
	while (i < j)
	{
		while (nums[j] >= pivot&&i < j)
			--j;
		if (j > i)
			nums[i++] = nums[j];
		while (nums[i] <= pivot&&i < j)
			++i;
		if (j > i)
			nums[j--] = nums[i];
	}
	nums[i] = pivot;
	return i;
}

void quick_sort(vector<int>& nums, int s, int e)
{
	if (s >= e)
		return;

	int pivot = partition(nums, s, e);
	quick_sort(nums, s, pivot - 1);
	quick_sort(nums, pivot + 1, e);
}

int main()
{
	vector<int> vi;
	int i = 0;
	while (cin >> i)
		vi.push_back(i);

	quick_sort(vi, 0, vi.size() - 1);
	for (int i : vi)
		cout << i << endl;
}