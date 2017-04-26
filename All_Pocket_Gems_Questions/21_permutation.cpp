#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution_1 {
public:

	void perm(vector<int> num, int k, int n, vector<vector<int> > &res) {
		if (k == n) {
			res.push_back(num);
		}
		else {
			for (int i = k; i <= n; i++) {
				int tmp = num[k];
				num[k] = num[i];
				num[i] = tmp;

				perm(num, k + 1, n, res);

				tmp = num[k];
				num[k] = num[i];
				num[i] = tmp;
			}
		}
	}

	vector<vector<int> > permute(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > res;
		perm(num, 0, (num.size() - 1), res);
		return res;
	}
};

class Solution_2 {
public:
	bool noswap(int k, int i, const vector<int> num) {
		for (int j = k; j<i; j++) {
			if (num[j] == num[i]) {
				return true;
			}
		}
		return false;
	}

	void perm(vector<int> num, int k, int n, vector<vector<int> > &res) {
		if (k == n) {
			res.push_back(num);
		}
		else {
			for (int i = k; i <= n; i++) {

				if (noswap(k, i, num)) { continue; }

				int tmp = num[k];
				num[k] = num[i];
				num[i] = tmp;

				perm(num, k + 1, n, res);

				tmp = num[k];
				num[k] = num[i];
				num[i] = tmp;
			}
		}
	}
	vector<vector<int> > permuteUnique(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > res;
		perm(num, 0, (num.size() - 1), res);
		return res;
	}
};

//int main()
//{
//	//Solution solution;
//	//vector<int> vi = { 1,1,2 };
//	//vector<vector<int>> answer = solution.permuteUnique(vi);
//	return 0;
//}