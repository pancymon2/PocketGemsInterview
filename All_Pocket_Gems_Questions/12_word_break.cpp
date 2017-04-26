#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

class Solution_word_break_1 {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> breakable(s.size() + 1, false);
		breakable[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (breakable[j] && wordDict.count(s.substr(j, i - j)))
				{
					//cout << s.substr(j, i - j) << endl;
					breakable[i] = true;
					break;
				}
			}
		}
		return breakable[s.size()];
	}
};

class Solution_word_break_2 {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<string> svec;
		vector<string> answer;
		if (!check(s, wordDict))
			return answer;
		helper(s, wordDict, svec, answer);
		return answer;
	}
private:
	bool check(string s, unordered_set<string>& wordDict)
	{
		vector<bool> breakable(s.size() + 1, false);
		breakable[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (breakable[j] && wordDict.count(s.substr(j, i - j)))
				{
					//cout << s.substr(j, i - j) << endl;
					breakable[i] = true;
					break;
				}
			}
		}
		return breakable[s.size()];
	}

	void helper(string s, unordered_set<string>& wordDict, vector<string>& svec, vector<string>& answer)
	{
		if (s.size() == 0)
		{
			string tmp;
			for (int i = 0; i < svec.size(); i++)
			{
				tmp += svec[i];
				tmp.push_back(' ');
			}
			tmp.pop_back();
			answer.push_back(tmp);
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (wordDict.count(s.substr(0, i + 1)))
			{
				svec.push_back(s.substr(0, i + 1));
				helper(s.substr(i + 1, s.size() - i - 1), wordDict, svec, answer);
				svec.pop_back();
			}
		}
	}
};

//int main()
//{
//	string s = "leetcode";
//	unordered_set<string>  dict = { "leet", "code" };
//	Solution solution;
//
//	vector<string> answer = solution.wordBreak(s, dict);
//	return 0;
//}