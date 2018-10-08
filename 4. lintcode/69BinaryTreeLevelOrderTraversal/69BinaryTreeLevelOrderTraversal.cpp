//https://www.jiuzhang.com/solution/binary-tree-level-order-traversal/
//http://www.lintcode.com/en/problem/binary-tree-level-order-traversal/
//https://leetcode.com/problems/binary-tree-level-order-traversal/description/
//https://www.youtube.com/watch?v=Tuij96VBdu8&t=4s
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its level order traversal as :
//[
//    [3],
//    [9, 20],
//    [15, 7]
//]



69. Sqrt(x)
DescriptionHintsSubmissionsDiscussSolution
#include <iostream>
#include <math.h>
#include <algorithm> 
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> result;
vector<vector<int>> levelOrder(TreeNode* root);
void DFS(TreeNode* root, int depth, vector<vector<int>>& ans);
vector<vector<int>> levelOrder2(TreeNode* root);
vector<vector<int>> levelOrder3(TreeNode* root);

void print(TreeNode *tree1);
//void dfs(TreeNode* root, int level, vector<vector<int>> &ans);

class Solution3 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {


		if (!root) return {};
		vector<vector<int>> ans;
		vector<TreeNode*> curr, next;
		curr.push_back(root);
		while (!curr.empty()) {
			ans.push_back({});
			for (TreeNode* node : curr) {
				ans.back().push_back(node->val);
				if (node->left) next.push_back(node->left);
				if (node->right) next.push_back(node->right);
			}
			curr.swap(next); // curr->left and ->right saved to next. 
			next.clear();
		}
		return ans;
	}
};

class Solution2 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;	
		int level = 0;
		dfs(root, level, ans);
		return ans;
	}
	void dfs(TreeNode*root, int level, vector<vector<int>> &ans)
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

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == NULL) {
			return ans;
		}
		queue<TreeNode* > myQueue;
		myQueue.push(root);
		while (myQueue.empty() == false) {
			vector<int> cur;
			for (int i = 0; i < myQueue.size(); i++) {
				TreeNode* temp = myQueue.front();
				myQueue.pop();
				cur.push_back(temp->val);
				if (temp->left != NULL) {
					myQueue.push(temp->left);
				}
				if (temp->right != NULL) {
					myQueue.push(temp->right);
				}
			}
			ans.push_back(cur);
		}
		return ans;

	}
};

class Solution4{
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == NULL)
		{
			return ans;
		}
		queue <TreeNode *> myQueue;		
		myQueue.push(root);
		while (!myQueue.empty()) //true if the underlying container's size is 0, false otherwise.
			//or 	while (myQueue.empty()== false)
		{	
			int size = myQueue.size();
			vector<int> cur; // reset the cur to size = 0;
			for (int i = 0; i < size; i++) {
				TreeNode *headRoot = myQueue.front();
				myQueue.pop();
				cur.push_back(headRoot->val);
				
				if (headRoot->left != NULL) {
					myQueue.push(headRoot->left);
				}
				if (headRoot->right != NULL) {
					myQueue.push(headRoot->right);
				}
				
			}
			ans.push_back(cur);
		}
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

    print(&tree1);
	Solution question;
	question.levelOrder(&tree1);
	Solution2 question2;
	question2.levelOrder(&tree1);
	Solution3 question3;
	question3.levelOrder(&tree1);
    
    levelOrder(&tree1);
	levelOrder2(&tree1);
	levelOrder3(&tree1);
    return 0;
}

vector<vector<int>> levelOrder2(TreeNode* root)
{
	vector<vector<int>> result;
	if (root == NULL) {
		return result; 
	}

	queue<TreeNode *> Q;
	Q.push(root);
	while (!Q.empty()) {
		int size = Q.size();
		vector<int> level;

		for (int i = 0; i < size; i++) {
			TreeNode *head = Q.front(); 
			Q.pop();
			level.push_back(head->val);
			if (head->left != NULL) {
				Q.push(head->left);
			}
			if (head->right != NULL) {
				Q.push(head->right);
			}
		}

		result.push_back(level);
	}

	return result;
}
vector<vector<int>> levelOrder3(TreeNode* root)
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
		cout<<endl;
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
    return ans;
}
vector<vector<int>> levelOrder(TreeNode* root) 
{
    vector<vector<int>> ans;
    DFS(root, 0 , ans);

    return ans; 
}

void DFS(TreeNode* root, int depth, vector<vector<int>>& ans) {
    if (!root)
    {
        return;
    }
    while (ans.size() <= depth)
    {
        ans.push_back({});
    }

    ans[depth].push_back(root->val); 
    DFS(root->left, depth + 1, ans);
    DFS(root->right, depth + 1, ans);
	//ans[depth].push_back(root->val);
}
void print(TreeNode *tree1)
{
    if (tree1 != NULL)
    {
        print(tree1->left);
        cout << tree1->val << endl;
        print(tree1->right);
    }


}


