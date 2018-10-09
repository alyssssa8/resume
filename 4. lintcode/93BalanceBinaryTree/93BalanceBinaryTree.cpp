//https://www.jiuzhang.com/solution/balanced-binary-tree/#tag-highlight-lang-cpp
//http://www.lintcode.com/en/problem/balanced-binary-tree/
//https://leetcode.com/problems/balanced-binary-tree/description/
//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as:
//a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//Example 1 :
//
//    Given the following tree[3, 9, 20, null, null, 15, 7] :
//
//     3
//    / \
//   9  20
//      / \
//     15   7
//    Return true.
//
//    Example 2:
//
//Given the following tree[1, 2, 2, 3, 3, null, null, 4, 4] :
//
//     1
//    / \
//    2   2
//   / \
//  3   3
// / \
//4   4

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

bool isBalanced(TreeNode* root);
void print(TreeNode *tree1);

class Solution {
public:
	bool isBalanced(TreeNode* root)
	{
		if (getDepth(root) == -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	int getDepth(TreeNode *root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int left = getDepth(root->left);
		int right = getDepth(root->right);

		if (left == -1 || right == -1 || abs(left - right) > 1)
		{
			return -1;
		}
		return max(left, right) + 1;

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

    //tree1.left = &tree2; // & to get the address of something
    tree1.right = &tree3;
    //tree2.left = &tree4; // & to get the address of something
    //tree2.right = &tree5;
    //tree3.left = &tree6; // & to get the address of something
    tree3.right = &tree7;
    isBalanced(&tree1);

    print(&tree1);

    return 0;
}
int getDepth(TreeNode *root);
bool isBalanced(TreeNode* root)
{
    return getDepth(root) != -1;
}

int getDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = getDepth(root->left);
	cout << "root->left:" << root->val << endl;
    int right = getDepth(root->right);

    if (left == -1 || right == -1 || abs(left - right) > 1)
    {
        return -1;
    }

    return max(left, right) + 1;

}
void print(TreeNode *tree1)
{
    if (tree1 != NULL)
    {
        cout << tree1->val << endl;
        print(tree1->left);
        print(tree1->right);
    }


}