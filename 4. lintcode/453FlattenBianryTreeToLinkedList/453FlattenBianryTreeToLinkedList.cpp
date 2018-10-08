//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
//http://www.lintcode.com/en/problem/flatten-binary-tree-to-linked-list/
//http://us.jiuzhang.com/solution/flatten-binary-tree-to-linked-list/
//
//Given a binary tree, flatten it to a linked list in - place.
//
//For example,
//Given
//
//1
/// \
//2   5
/// \   \
//3   4   6
//
//
//The flattened tree should look like :
            
//     1
//    / \
//   2   5
//    \   \ 
//     3   6
//      \    
//       4    
//            
//              
//
//1
// \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

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

 void flatten(TreeNode* root);
void print(TreeNode *tree1);


class Solution {
public:
	void flatten(TreeNode* root)
	{
		if (!root)
		{
			return;
		}
		flatten(root->left);
		flatten(root->right);

		TreeNode * temp = root->right;

		root->right = root->left;
		root->left = nullptr;
		while (root->right)
		{
			root = root->right;
		}
		root->right = temp;
	}
};

int main()
{
    TreeNode tree1(1);
    TreeNode tree2(2);
    TreeNode tree3(5);
    TreeNode tree4(3);
    TreeNode tree5(4);
    //TreeNode tree6(6);
    TreeNode tree7(6);

    tree1.left = &tree2; // & to get the address of something
    tree1.right = &tree3;
    tree2.left = &tree4; // & to get the address of something
    tree2.right = &tree5;
    //tree3.left = &tree6; // & to get the address of something
    tree3.right = &tree7;
   
  

    flatten(&tree1);
    print(&tree1);

    return 0;
}
/*
void flatten(TreeNode* root)
{
    
    if (root == NULL)
    {
        return;
    }
    while (root)
    {
        if (root->left)
        {
            TreeNode *pre = root->left;

            while (pre->right)
            {
                pre = pre->right;
            }

            pre->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }

    print(root);
 

}

*/
void flatten(TreeNode* root)
{
    if (!root)
    {
        return;
    }
    flatten(root->left);
    flatten(root->right);

    TreeNode *tmp = root->right;
    root->right = root->left;
    root->left = nullptr;
	//cout << "tmp: " << tmp->val << "  root->right: " << root->right->val << "  root->left: " << root->left->val << endl;
	cout << "root: " << root->val << endl;

    while (root->right)
    {
        root = root->right;
    }

    root->right = tmp;

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