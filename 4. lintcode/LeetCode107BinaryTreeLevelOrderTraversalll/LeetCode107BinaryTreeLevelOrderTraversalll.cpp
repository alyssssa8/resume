//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
//
//Given a binary tree, return the bottom - up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its bottom - up level order traversal as :
//[
//	[15, 7],
//	[9, 20],
//	[3]
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

 class Test2 {
 public:
	 vector<vector<int>> levelOrderBottom(TreeNode* root) {
		 vector<vector<int>>ans;
		 int level = 0;
		 dfs(root, level, ans);
		 reverse(ans.begin(), ans.end());
		 return ans;
		
	 }
 private:
	 void dfs(TreeNode *root, int level, vector<vector<int>> &ans)
	 {
		 if (!root)
		 {
			 return;
		 }
		 while (ans.size() <= level)
		 {
			 ans.push_back({});
		 }

		 ans[level].push_back(root->val);
		 dfs(root->left, level + 1, ans);
		 dfs(root->right, level + 1, ans);


		
		 
	 }
	
 };


 class Test {
 public:
	 vector<vector<int>> levelOrderBottom(TreeNode* root) {
		 vector<vector<int>>ans;
		 queue<TreeNode *>myQueue;
		 TreeNode *headRoot;
		 if (!root)
		 {
			 return ans;
		 }

		 myQueue.push(root);
		 while (!myQueue.empty())
		 {
			 int size = myQueue.size();
			 vector<int>cur;
			 for (int i = 0; i < size; i++)
			 {
				 headRoot = myQueue.front();
				 myQueue.pop();
				 cur.push_back(headRoot->val);

				 if (headRoot->left != NULL)
				 {
					 myQueue.push(headRoot->left);
				 }
				 if (headRoot->right != NULL)
				 {
					 myQueue.push(headRoot->right);
				 }

			 }

			 ans.push_back(cur);

		 }
		 reverse(ans.begin(), ans.end());
		 return ans;
	 }

 };

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int> > ret;
		ret.clear();
		if (root == NULL)
			return ret;
		queue<TreeNode*> S;
		S.push(root);
		S.push(NULL);
		vector<int> tmp;
		while (!S.empty()) {
			//travesal current level
			TreeNode* p = S.front();
			S.pop();
			if (p != NULL)
			{
				tmp.push_back(p->val);
				if (p->left)
					S.push(p->left);
				if (p->right)
					S.push(p->right);
			}
			else {
				if (!tmp.empty())
				{
					S.push(NULL);
					ret.push_back(tmp);
					tmp.clear();
				}
			}
		}

		reverse(ret.begin(), ret.end());
		return ret;
	}

};


class Solution2 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		DFS(root, 0 /* depth */, ans);
		reverse(ans.begin(), ans.end());
		return ans;
	}
private:
	void DFS(TreeNode* root, int depth, vector<vector<int>>& ans) {
		if (!root) return;
		// Works with pre/in/post order
		while (ans.size() <= depth) ans.push_back({});
		ans[depth].push_back(root->val); // pre-order
		DFS(root->left, depth + 1, ans);
		DFS(root->right, depth + 1, ans);
	}

};


class Solution3 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		if (!root)
		{
			return {};
		}

		vector<vector<int>> ans;
		vector<TreeNode*> curr, next;
		curr.push_back(root);

		while (!curr.empty())
		{
			ans.push_back({});
			//for (int i = 0; i < size; i++)
			cout << endl;
			for (TreeNode* node : curr)
			{
				cout << node->val << endl;
				ans.back().push_back(node->val);
				if (node->left)
				{
					cout << node->left->val << endl;
					next.push_back(node->left);
				}
				if (node->right)
				{
					cout << node->right->val << endl;
					next.push_back(node->right);
				}
			}
			cout << "_______________________________" << endl;
			curr.swap(next);
			next.clear();
		}



		reverse(ans.begin(), ans.end());
		return ans;
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
	//isBalanced(&tree1);

	//print(&tree1);

	Solution question;
	Solution2 question2;
	question.levelOrderBottom(&tree1);
	question2.levelOrderBottom(&tree1);

	Solution3 question3;
	question3.levelOrderBottom(&tree1);
	Test question4;
	question.levelOrderBottom(&tree1);
	Test2 question5;
	question5.levelOrderBottom(&tree1);
	return 0;

}