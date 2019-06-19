//leetcode
//http://www.lintcode.com/en/problem/binary-tree-paths/
//https://leetcode.com/problems/binary-tree-paths/description/
//https://www.jiuzhang.com/solution/binary-tree-paths/
//Given a binary tree, return all root - to - leaf paths.
//
//For example, given the following binary tree :
//
//    1
//   / \
//  2    3
//  /\
// 5
//All root - to - leaf paths are :
//
//["1->2->5", "1->3"]

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


class Test {
private:
	vector<string> result;

public:

	vector<string> binaryTreePaths(TreeNode* root) {
	
		if (!root)
		{
			return result;
		}
		dfs(root, to_string(root->val));
		return result;
	}
	void dfs(TreeNode* root, string tempResult)
	{

		if (!root->left && !root->right) {
			result.push_back(tempResult);
			return;
		}
	
		if (root->left)
		{
			dfs(root->left, tempResult + "->" + to_string(root->left->val));
		}
		if (root->right)
		{
			dfs(root->right, tempResult + "->" + to_string(root->right->val));
		}
		
	}
};
class Solution {

private:
    vector<string> result;

public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        //vector<string> result;
        if (!root) return result;

        binaryTreePaths(root, to_string(root->val));
        return result;
    }
    void binaryTreePaths(TreeNode* root, string t)
    {
        //if (!root->left && !root->right) {
            if (!root) {
            result.push_back(t);
            return;
        }

        if (root)
        {
            binaryTreePaths(root->left, t + "->" + to_string(root->val));

        }
        if (root)
        {
            binaryTreePaths(root->right, t + "->" + to_string(root->val));
        }
    }

/*

public:
    vector<string> binaryTreePaths(TreeNode2* root) {
        vector<string> result;
        if (!root) return result;

        binaryTreePaths(result, root, to_string(root->val));
        return result;
    }
    void binaryTreePaths(vector<string>& result, TreeNode2* root, string t) {
        if (!root->left && !root->right) {
            cout << "$$$$$$$$$$$$$$$$$$$$$$" << endl;
            cout << t << endl;
            cout << "$$$$$$$$$$$$$$$$$$$$$$" << endl;

            result.push_back(t);

            return;
        }


        cout << t << endl;
        if (root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
        cout << t << endl;
        if (root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
        cout << t << endl;
        cout << "__________________________________" << endl;

    }
    */
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
	TreeNode tree8(800);
	TreeNode tree9(900);

    tree1.left = &tree2; // & to get the address of something
    tree1.right = &tree3;
    //tree2.left = &tree4; // & to get the address of something
    tree2.right = &tree5;
 //   tree3.left = &tree6; // & to get the address of something
 //   tree3.right = &tree7;
	//tree4.left = &tree8; // & to get the address of something
	//tree4.right = &tree9;
    Solution s; // instance of solution
    vector<string> result =s.binaryTreePaths(&tree1);
    // << "the out put node " << endl;
     
    vector<string>::iterator iter;
    for (iter = result.begin(); iter != result.end(); iter++)
    {
        cout << *iter << endl; // if vector is a struct, (*iter).member or iter->member
    }
    Solution question;
    question.binaryTreePaths(&tree1);

    print(&tree1);

    return 0;
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