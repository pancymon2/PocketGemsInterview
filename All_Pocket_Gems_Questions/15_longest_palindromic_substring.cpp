#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution_n2 {
public:
	string longestPalindrome(string s) {
		int l = 0;
		int r = 0;
		int len = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int max1 = expand(s, i, i);
			int max2 = expand(s, i, i + 1);
			//int len = Math.max(len1, len2);
			//if (len > end - start) {
			//	start = i - (len - 1) / 2;
			//	end = i + len / 2;
			//}
			if (max1 > len)
			{
				len = max1;
				l = i - len / 2;
				r = i + len / 2;
			}
			if (max2 > len)
			{
				len = max2;
				l = i - len / 2 + 1;
				r = i + len / 2;
			}
		}
		return s.substr(l, len);
	}
private:
	int expand(string& s, int l, int r)
	{
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			--l;
			++r;
		}
		return r - l - 1;
	}
};

class Solution {
public:
	string longestPalindrome(string s) {
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); i++) {
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = max(len1, len2);
			if (len > end - start) {
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

private:
	int expandAroundCenter(string s, int left, int right) {
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R]) {
			L--;
			R++;
		}
		return R - L - 1;
	}
};

//int main()
//{
//	Solution solution;
//	string s = "a";
//	string answer = solution.longestPalindrome(s);
//	cout << answer << endl;
//	return 0;
//}