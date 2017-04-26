class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
};

class Solution
{
public:
	TreeNode* inorder_successor_p(TreeNode* n, TreeNode* root)
	{
		TreeNode* succ = nullptr;
		if (n->right)
		{
			succ = n->right;
			while (succ->left)
				succ = succ->left;
		}
		else
		{
			succ = n->parent;
			while (succ&&n == succ->right)
			{
				n = succ;
				succ = succ->parent;
			}
		}
		return succ;
	}

	TreeNode* inorder_successor_np(TreeNode* n, TreeNode* root)
	{
		TreeNode* succ = nullptr;
		if (n->right)
		{
			succ = n->right;
			while (succ->left)
				succ = succ->left;
		}
		else
		{
			while (root)
			{
				if (root->val > n->val)
				{
					succ = root;
					root = root->left;
				}
				else if (root->val < n->val)
					root = root->right;
				else
					break;
			}
		}
		return succ;
	}
};