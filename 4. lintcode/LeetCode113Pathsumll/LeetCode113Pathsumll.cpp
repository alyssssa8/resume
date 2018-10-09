//https://leetcode.com/problems/path-sum-ii/description/
//http://zxi.mytechroad.com/blog/tree/leetcode-113-path-sum-ii/
//Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.
//
//Note : A leaf is a node with no children.
//
//	Example :
//
//	Given the below binary tree and sum = 22,
//
//	5
//	/ \
//	4   8
//	/   / \
//	11  13  4
//	/ \ / \
//	7    2  5   1
//	Return:
//
//[
//	[5, 4, 11, 2],
//	[5, 8, 4, 5]
//]
#include <iostream>
#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include <vector>




using namespace std;





//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Test {
private:
	vector <vector<int>> ans;
	vector <int > tempAns;
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {		
		dfs(root, sum);
		return ans;
	}

	void dfs(TreeNode* root, int sum)
	{
		if (root == NULL)
		{
			return;
		}
		if (root->val == sum && root->left == NULL && root->right == NULL)
		{
			ans.push_back(tempAns);
			ans.back().push_back(root->val);
			return;
		}
		tempAns.push_back(root->val);
		dfs(root->left, sum - root->val);
		dfs(root->right, sum - root->val);
		tempAns.pop_back();

	}
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ans;
		vector<int> curr;
		pathSum(root, sum, curr, ans);
		return ans;
	}
private:
	void pathSum(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ans) {
		if (root == nullptr) return;
		if (root->left == nullptr && root->right == nullptr) {
			if (root->val == sum) {
				ans.push_back(curr); // will need to pop curr. is add val first, will left one value which should be poped. 
				ans.back().push_back(root->val);
				
				
			}
			return;
		}

		curr.push_back(root->val);
		int new_sum = sum - root->val;
		pathSum(root->left, new_sum, curr, ans);
		pathSum(root->right, new_sum, curr, ans);
		curr.pop_back();
	}
};


int main()
{
	TreeNode tree1(5);
	TreeNode tree2(4);
	TreeNode tree3(8);
	TreeNode tree4(11);
	TreeNode tree5(13);
	TreeNode tree6(4);
	TreeNode tree7(7);
	TreeNode tree8(2);
	TreeNode tree9(5);
	TreeNode tree10(1);
	tree1.left = &tree2; // & to get the address of something
	tree1.right = &tree3;
	tree2.left = &tree4; // & to get the address of something
	tree4.left = &tree7;
	tree4.right = &tree8;
	tree3.left = &tree5; // & to get the address of something
	tree3.right = &tree6;
	tree6.left = &tree9;
	tree6.right = &tree10;
	int sum = 22;
	Solution question;
	question.pathSum(&tree1, sum);

	Test question3;
	question3.pathSum(&tree1, sum);
	return 0;

}

