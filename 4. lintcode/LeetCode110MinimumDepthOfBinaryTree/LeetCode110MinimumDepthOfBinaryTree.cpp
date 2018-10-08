

//https://leetcode.com/problems/minimum-depth-of-binary-tree/description/


//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given binary tree[3, 9, 20, null, null, 15, 7],
//
//	3
//	/ \
//	9	20		if (left == 0 || right == 0){
//		/ \		return max(left, right) + 1;
//		   7    }
//	return its minimum depth = 2.

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
	int minDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}

		queue <TreeNode *> myQueue;
		myQueue.push(root);
		int level = 0;
		while (!myQueue.empty())
		{
			level++;
			int count = myQueue.size();
			while (count-- != 0)
			{
				TreeNode* temp = myQueue.front();
				myQueue.pop();
				if (!temp->left && !temp->right)
				{
					return level;
				}
				if (temp->left)
				{
					myQueue.push(temp->left);
				}
				if (temp->right) {
					myQueue.push(temp->right);
				}

			}

		}
		return level;
	}
};
class Test {

	
public:
	int minDepth(TreeNode* root) {


		if (!root)
		{
			return 0;
		}

		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (left == 0 && right == 0)
		{
			return 1;
		}
		else if (left == 0 || right == 0) { 
			return max(left, right) + 1;
		}
		else {
			return min(left, right) + 1;
		}
		
		
	}
};
class Solution {
public:
	int minDepth(TreeNode* root) {

		if (!root)
			return 0;

		queue<TreeNode*> q;
		q.push(root);

		int level = 0;
		while (true)
		{
			int node_count = q.size();
			if (!node_count)
				break;

			level++;
			while (node_count--)
			{
				TreeNode* n = q.front();
				q.pop();
				if (!n->left && !n->right)
					return level;

				if (n->left)
					q.push(n->left);

				if (n->right)
					q.push(n->right);
			}
		}
		return level;

	}
};
class Solution2 {
public:
	int minDepth(TreeNode* root) {

		if (!root)
			return 0;

		int left = minDepth(root->left);
		int right = minDepth(root->right);
		//no leaves,return 1 level  
		if (left == 0 && right == 0) {
			return 1;
		}
		//if have only left leaf or right leaf, return max
		else if (left == 0 || right == 0) {
			return max(left, right) + 1;
		}
		//both have leaves, return min
		else {
			return min(left, right) + 1;
		}

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
	//tree3.left = &tree6; // & to get the address of something
	//tree3.right = &tree7;

	Solution question;
	question.minDepth(&tree1);
	Solution2 question2;
	question2.minDepth(&tree1);

	Test question3;
	question3.minDepth(&tree1);
	Test2 question4;
	question4.minDepth(&tree1);
	return 0;

}

bool hasPathSum(TreeNode* root, int sum) {

	if (!root)
		return 0;
	if (root->left == nullptr && root->right == nullptr) return root->val == sum;
	int new_sum = sum - root->val;
	return hasPathSum(root->left, new_sum) || hasPathSum(root->right, new_sum);

}