//https://www.jiuzhang.com/solutions/maximum-depth-of-binary-tree/
//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
//http://www.lintcode.com/en/problem/maximum-depth-of-binary-tree/
//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//
// 3
/// \
//9  20
//   / \
//  15  7
//return its depth = 3.
//
//Given a binary tree as follow :
//
//   1
//  / \
//  2   3
// / \
//4   5
//The maximum depth is 3.


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

int maxDepth(TreeNode* root);
void print(TreeNode *tree1);


class Test2 {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}

		int left = maxDepth(root->left);
		int right = maxDepth(root->right);


		return max(left, right) + 1;
	}
};

class Test {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}

		int left = maxDepth(root->left);
		int right = maxDepth(root->right);

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

    tree1.left = &tree2; // & to get the address of something
    tree1.right = &tree3;
    tree2.left = &tree4; // & to get the address of something
    tree2.right = &tree5;
    tree3.left = &tree6; // & to get the address of something
    tree3.right = &tree7;
    maxDepth(&tree1);

    print(&tree1);
	Test2 question2;
	question2.maxDepth(&tree1);


	Test question;
	question.maxDepth(&tree1);
    return 0;
}
int maxDepth(TreeNode* root)
{

    if (root==NULL)
    {
        return 0;
    }


    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

   ///* if (left > right)
   // {
   //     left++;
   // }
   // else
   // {
   //     right++;
   // }*/

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