//https://leetcode.com/problems/path-sum/description/
//Given a binary tree and a sum, determine if the tree has a root - to - leaf path such that adding up all the values along the path equals the given sum.
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
//	/ \      \
//	7    2      1
//	return true, as there exist a root - to - leaf path 5->4->11->2 which sum is 22.


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

class Test2 {
public:
	bool hasPathSum(TreeNode* root, int sum)
	{
		if (!root)
			return 0;
		if (root->left == nullptr && root->right == nullptr) // if input is: [], 0 ,sum = 0 will not work.  
		{
			return root->val == sum;
		}
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

class Test {
public:
	bool hasPathSum(TreeNode* root, int sum)
	{
		if (!root)
		{
			return false;
		}
		if (root->val == sum && root->left == NULL && root->right == NULL)
		{
			return true;
		}
		if (hasPathSum(root->left, sum - root->val)) return true;
		if (hasPathSum(root->right, sum - root->val)) return true;
		return false;
	}
};
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {

		if (!root)
			return 0;

        /*if (root == NULL) { 
            return false;
        }*/
		if (root->left == nullptr && root->right == nullptr) return root->val == sum;
		int new_sum = sum - root->val;
		return hasPathSum(root->left, new_sum) || hasPathSum(root->right, new_sum);

	}
	
};

class Solution2 {
public:
	bool hasPathSum(TreeNode* root, int sum)
	{
		if (root == NULL)  return false;
		//else if (root->val>sum) return false;      This should be avoided as there can be also negative integers as node values
		else if (root->val == sum && root->left == NULL && root->right == NULL)
			return true;
        /*if (sum < 0) {
            return false;  // does not work, need to think about negative number
        }*/

        		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);

		if (hasPathSum(root->left, sum - root->val)) return true;
		if (hasPathSum(root->right, sum - root->val)) return true;
		return false;

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
	int sum = 22;
	Solution question;
	question.hasPathSum(&tree1, sum);
	Solution2 question2;
	question2.hasPathSum(&tree1, sum);
	return 0;

}

