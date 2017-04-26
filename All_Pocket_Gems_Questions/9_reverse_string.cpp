//What constitutes a word ?
//A sequence of non - space characters constitutes a word.
//Could the input string contain leading or trailing spaces ?
//Yes.However, your reversed string should not contain leading or trailing spaces.
//How about multiple spaces between two words ?
//Reduce them to a single space in the reversed string.
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		int l = 0;
		while (s[l] == ' ')
			l++;
		if (l != 0)
			s.erase(0, l);
		l = 0;

		int r = s.size() - 1;
		while (s[r] == ' ')
			r--;
		if (r != s.size() - 1)
			s.erase(r + 1, s.size() - 1 - r);
		r = 0;
		while (r<s.size())
		{
			while (s[r] != ' '&&r<s.size())
				++r;
			reverse(s, l, r - 1);
			if (r == s.size())
				break;
			l = r;
			while (s[r] == ' ')
				r++;
			if (r - l > 1)
			{
				s.erase(l, r - l - 1);
			}
			r = ++l;

		}
		reverse(s, 0, s.size() - 1);
	}

	void reverse(string &s, int l, int r)
	{
		//int l = 0;
		//int r = s.size() - 1;
		while (l < r)
		{
			char tmp = s[l];
			s[l++] = s[r];
			s[r--] = tmp;
		}
	}
};

