//
//https://leetcode.com/problems/symmetric-tree/description/
//
//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//
//For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//But the following[1, 2, 2, null, 3, null, 3] is not:
//1
/// \
//2   2
//\   \
//3    3

#include <iostream>
#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include<unordered_map>
#include <vector>
using namespace std;



//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution2 {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		stack<TreeNode*> sl, sr;
		sl.push(root);
		sr.push(root);
		TreeNode * lp = root->left, *rp = root->right;
		while (lp || !sl.empty() || rp || !sl.empty()) {
			if ((!lp && rp) || (lp && !rp)) return false;
			if (lp && rp) {
				if (lp->val != rp->val) return false;
				sl.push(lp);
				sr.push(rp);
				lp = lp->left;
				rp = rp->right;
			}
			else {
				lp = sl.top()->right;
				rp = sr.top()->left;
				sl.pop();
				sr.pop();
			}
		}
		return true;

	}
};

//own writting
class Solution3 {
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root, root);

    }

    int dfs(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 != NULL) {
            return 0;
        }
        if (root2 == NULL && root1 != NULL) {
            return 0;
        }
        if (root1 == NULL && root2 == NULL) {
            return 1;
        }
        if (root1->val != root2->val) {
            return 0;
        }
        int left = dfs(root1->left, root2->right);
        int right = dfs(root1->right, root2->left);
        if (left == 0 || right == 0) {
            return 0;
        }
        return 1;
    }
};
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return helper(root->left, root->right);
	}
	bool helper(TreeNode* left, TreeNode* right) {
		if (!left && !right) return true;
		if (!left || !right) return false;
		return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
	}
};
int main()
{
	TreeNode tree1(1);
	TreeNode tree2(2);
	TreeNode tree3(3);
	TreeNode tree4(4);
	TreeNode tree5(5);
	TreeNode tree6(6);
	TreeNode tree7(7);
	tree1.left = &tree2; // & to get the address of something
	tree1.right = &tree3;
	tree2.left = &tree4; // & to get the address of something
	tree2.right = &tree5;
	tree3.left = &tree6; // & to get the address of something
	tree3.right = &tree7;

	Solution question;
	question.isSymmetric(&tree1);
	Solution2 question2;
	question2.isSymmetric(&tree1);

	return 0;
}