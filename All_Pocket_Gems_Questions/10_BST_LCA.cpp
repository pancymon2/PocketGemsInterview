#include<stddef.h>
#include<iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_BT {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)
			return root;
		if (root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (!left)
			return right;
		if (!right)
			return left;
		return root;
	}
};

class Solution_BST {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)
			return root;
		if (root->val > p->val&&root->val > q->val)
			return lowestCommonAncestor(root->left, p, q);

		if (root->val < p->val&&root->val < q->val)
			return lowestCommonAncestor(root->right, p, q);

		return root;
	}
};

class Solution_BT_Find_PQ {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		bool find_p = false;
		bool find_q = false;
		TreeNode* answer = helper(root, p, q, find_p, find_q);
		if (find_p&&find_q)
			return answer;
		return NULL;
	}

	TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q, bool& find_p, bool& find_q)
	{
		if (!root)
			return root;

		TreeNode* left = helper(root->left, p, q, find_p, find_q);
		TreeNode* right = helper(root->right, p, q, find_p, find_q);

		if (root == p)
		{
			find_p = true;
			//cout << "find p" << endl;
			return root;
		}
		if (root == q)
		{
			find_q = true;
			//cout << "find q" << endl;
			return root;
		}

		if(left&&right)
			return root;
		return left ? left : right;
	}
};

