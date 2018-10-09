
//https://www.jiuzhang.com/solution/minimum-subtree/
//Given a binary tree, find the subtree with minimum sum.Return the root of the subtree.
//Example
//Given a binary tree :
//        1
//       / \
//    - 5   2
//    / \   / \
//    0  2  -4 -5
//return the node 1.
//1+2+2-4-5-5=-9


#include <iostream>
#include <math.h>
#include <algorithm> 
using namespace std;

//Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {//"this" means the pointer of current object,this-> left means the member "left" of object (*this)
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {

private:
	TreeNode * ansNode = nullptr;
	int minSum = INT_MAX;

public:
	
	TreeNode* findSubtree(TreeNode* root) {


		dfs(root);
		return ansNode;
	}

	int dfs(TreeNode * root)
	{

		if (root == NULL)
		{
			return 0;
		}
		int left = dfs(root->left);
		int right = dfs(root->right);

		int tempSum = left + right + root->val;
		if (tempSum < minSum)
		{
			minSum = tempSum;
			ansNode = root;
		}

		return tempSum;

	}
};
class Solution {

private:
    TreeNode * result = nullptr;
    int minumun_weight = INT_MAX;
public:

    TreeNode * findSubtree2(TreeNode* root) {
        int minumun=helper(root);
        cout << " the min " << endl;
        cout << minumun << endl;
        return result;
    }
    int helper(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);

        cout << "root" << endl;
        cout << root->val << endl;
        cout << "left" << endl;
        cout << left << endl;
        cout << "right" << endl;
        cout << right << endl;
        cout << "____________________________________________" << endl;

        if (minumun_weight >= left + right + root->val)
        {
            minumun_weight = left + right + root->val;
            result = root;
        }      
       
        return  left + right + root->val;
    }


};


void print(TreeNode *tree1);
int main()
{
    TreeNode tree1(100);
    TreeNode tree2(200);
    TreeNode tree3(300);
    TreeNode tree4(400);
    TreeNode tree5(500);
    TreeNode tree6(600);
    TreeNode tree7(700);

    tree1.left = &tree2; // & to get the address of something
    tree1.right = &tree3;
    tree2.left = &tree4; // & to get the address of something
    tree2.right = &tree5;
    tree3.left = &tree6; // & to get the address of something
    tree3.right = &tree7;
    Solution s; // instance of solution
    TreeNode *result = s.findSubtree2(&tree1);
    cout << "the out put node " << endl;
    cout << result->val << endl;

    print(&tree1);

    return 0;
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