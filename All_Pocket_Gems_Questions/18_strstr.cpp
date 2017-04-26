#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution_brute_force {
public:
	int strStr(string haystack, string needle) {
		if (!needle.size())
			return 0;

		int j = 0, i = 0;
		while (j < needle.size() && i < haystack.size())
		{
			if (haystack[i] == needle[j])
			{
				++i;
				++j;
				if (j == needle.size())
					return i - j;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}

		return j == needle.size() ? i - j : -1;
	}
};


class Solution_KMP {
public:
	int strStr(string haystack, string needle) {

		if (!needle.size())
			return 0;

		int nlen = needle.size();
		vector<int> next(nlen);
		
		cal_next(needle, next);

		int i = 0;
		int j = 0;
		int hlen = haystack.size();
		//int pLen = strlen(p);
		while (i < hlen && j < nlen)
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				j = next[j];
			}
		}
		if (j == nlen)
			return i - j;
		else
			return -1;

	}

private:
	void cal_next(string needle, vector<int>& next)
	{
		int nlen = needle.size();
		next[0] = -1;
		int k = -1;
		int j = 0;
		while (j < nlen - 1)
		{
			if (k == -1 || needle[j] == needle[k])
			{
				++k;
				++j;
				next[j] = k;
			}
			else
			{
				k = next[k];
			}
		}
	}
};


//int main()
//{
//	string s1 = "aaaaaaab";
//	string s2 = "aaaab";
//	Solution_KMP solution;
//	cout << solution.strStr(s1, s2);
//	return 0;
//}