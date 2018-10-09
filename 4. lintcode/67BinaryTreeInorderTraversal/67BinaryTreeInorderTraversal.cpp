//https://www.jiuzhang.com/solution/binary-tree-inorder-traversal/
//http://www.lintcode.com/en/problem/binary-tree-inorder-traversal/
//https://leetcode.com/problems/binary-tree-inorder-traversal/description/
//
//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example :
//Given binary tree[1, null, 2, 3],
//1
//\
//2
///
//3
//return[1, 3, 2].


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
vector<int> result;
vector<int> inorderTraversal(TreeNode* root);
void inorder( TreeNode *root);
void print(TreeNode *tree1);


class Solution {
private:
	vector<int> ans;
public:
	
	vector<int> inorderTraversal(TreeNode* root)
	{

		dfs(root);
		return ans;

	}

	void dfs(TreeNode*root)
	{
		if (root == NULL)
		{
			return;
		}

		dfs(root->left);
		cout << "root->value: " << root->val << endl;
		ans.push_back(root->val);
		dfs(root->right);
		cout << "__________________" << endl;

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

    vector<int> result;
    inorderTraversal(&tree1);

	Solution question;
	question.inorderTraversal(&tree1);
    return 0;
}

vector<int> inorderTraversal(TreeNode* root)
{
   
    if (!root)
    {
        return result;
    }
    inorder(root);

    vector<int>::iterator iter;
    for (iter = result.begin(); iter != result.end(); iter++)
    {
        cout << *iter << endl; // if vector is a struct, (*iter).member or iter->member
    }


    return result;
}

void inorder( TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder( root->left);
    cout << root->val << endl;
    result.push_back(root->val);
    inorder( root->right);

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