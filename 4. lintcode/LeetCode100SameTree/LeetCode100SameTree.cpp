
//
//
//https://leetcode.com/problems/same-tree/description/
//https://www.youtube.com/watch?v=VJVQpqPRptM
//http://zxi.mytechroad.com/blog/tree/leetcode-100-same-tree/
//https://www.youtube.com/watch?v=VJVQpqPRptM
//
//Given two binary trees, write a function to check if they are the same or not.
//
//Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
//
//Example 1:
//
//Input:		  1		  1
//			/	\	 /  \
//			2   3    2   3
//
//	[1, 2, 3], [1, 2, 3]
//
//	Output: true
//	Example 2 :
//
//	Input : 1         1
//			/			 \
//			2             2
//
//	[1, 2], [1, null, 2]
//
//	Output: false
//	Example 3 :
//
//	Input :	1         1
//			/	 \	 / \
//			2   1   1   2
//
//	[1, 2, 1], [1, 1, 2]
//
//	Output: false

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
	bool isSameTree(TreeNode* p, TreeNode* q) {

		queue<pair<TreeNode*, TreeNode*> > myQueue;
		pair<TreeNode*, TreeNode*> node = make_pair(p, q);
		myQueue.push(node);
		while (!myQueue.empty())
		{
			pair<TreeNode *, TreeNode *> temp = myQueue.front();
			myQueue.pop();
			if (!temp.first && !temp.second) continue;
			else if (!temp.first || !temp.second) return false;
			else {
				if (temp.first->val != temp.second->val)
				{			
					return false;
				}
				else {
					myQueue.push(make_pair(temp.first->left, temp.second->left));
					myQueue.push(make_pair(temp.first->right, temp.second->right));
				}
			}
		}
		return true;
	}
};

class Test {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {

		if (p == NULL && q == NULL)
		{
			return true;
		}
		if (p == nullptr || q == NULL)
		{
			return false;
		}

		if (p->val != q->val)
		{
			return false;
		}

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

	}
};



class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// Both are emtry: same
		if (!p && !q) return true;
		// One is emtry: not the Same
		if (!p || !q) return false;
		// Both are not emptry, compare the root value
		if (p->val != q->val) return false;
		// Compare left-subtree and right-subtree recursively.
		return isSameTree(p->left, q->left)
			&& isSameTree(p->right, q->right);
	}
};

class Solution2 {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {

		if (!p && !q) return true;
		else if (!p || !q) return false;
		else {
			queue<pair<TreeNode*, TreeNode*> > qu;
			pair<TreeNode*, TreeNode*> node = make_pair(p, q);
			qu.push(node);
			while (!qu.empty()) {
				pair<TreeNode*, TreeNode*> ha = qu.front();
				qu.pop();
				if (!ha.second && !ha.first) continue;
				else if (!ha.first || !ha.second) return false;
				else {
					if (ha.first->val != ha.second->val) {
						return false;
					}
					else {
						qu.push(make_pair(ha.first->left, ha.second->left));
						qu.push(make_pair(ha.first->right, ha.second->right));
					}
				}
			}
		}
		return true;

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

	TreeNode tree10(1);
	TreeNode tree20(2);
	TreeNode tree30(3);
	TreeNode tree40(4);
	TreeNode tree50(5);
	TreeNode tree60(6);
	TreeNode tree70(7);


	tree1.left = &tree2; // & to get the address of something
	tree1.right = &tree3;
	tree2.left = &tree4; // & to get the address of something
	tree2.right = &tree5;
	tree3.left = &tree6; // & to get the address of something
	tree3.right = &tree7;

	tree10.left = &tree20; // & to get the address of something
	tree10.right = &tree30;
	tree20.left = &tree40; // & to get the address of something
	tree20.right = &tree50;
	tree30.left = &tree60; // & to get the address of something
	tree30.right = &tree70;
	
	Solution question;
	question.isSameTree(&tree1, &tree10);
	Solution2 question2;
	question2.isSameTree(&tree1, &tree10);

	Test question3;
	question3.isSameTree(&tree1, &tree10);
	return 0;

}