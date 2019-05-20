//https://leetcode.com/problems/sum-of-left-leaves/description/
//Find the sum of all left leaves in a given binary tree.
//
//Example :
//
//	3
//	/ \
//	9  20
//	/ \
//	15   7
//
//	There are two left leaves in the binary tree, with values 9 and 15 respectively.Return 24.


#include <iostream>
#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include<unordered_map>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
	int sumOfLeftLeaves(TreeNode* root) {

		if (root == NULL) {
			return 0;
		}
		int sum = 0;
		if (root->left && !root->left->left && !root->left->right) {// forgot root->left
			sum = root->left->val;
            cout << "sum: "<<sum << endl;
		}
        //cout << "**sum: " << sum<<"  sum + sumOfLeftLeaves(root->left)"<< sumOfLeftLeaves(root->left)<<"  sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right)"<< sumOfLeftLeaves(root->right) << endl;
		return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

	}
};

/*
class Solution {
private:
	int sum = 0;
public:
	int sumOfLeftLeaves(TreeNode* root) {
		
		dfs(root);
		return sum;
	}
	void dfs(TreeNode* root) {
		if(root == NULL) {
			return ;
		}

		dfs(root->left); // this is wrong, when root is root->right, if add value, will add the right value. 
		sum += root->val;
		dfs(root->right);
		return;
	}

};
*/

class GfG
{
public:
    static int i;

    GfG()
    {
        // Do nothing 
    };
    void change() {
        i = i * i;
    }
};

int GfG::i = 1;
int main()
{// C++ program to demonstrate static 
// variables inside a class 



        GfG obj;
        // prints value of i 
        obj.change();
        cout << obj.i;
    



	TreeNode tree1(3);
	TreeNode tree2(9);
	TreeNode tree3(20);
	TreeNode tree4(4);
	TreeNode tree5(5);
	TreeNode tree6(15);
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
	//tree2.left = &tree4; // & to get the address of something
	//tree2.right = &tree5;
	tree3.left = &tree6; // & to get the address of something
	tree3.right = &tree7;

	tree10.left = &tree20; // & to get the address of something
	tree10.right = &tree30;
	tree20.left = &tree40; // & to get the address of something
	tree20.right = &tree50;
	tree30.left = &tree60; // & to get the address of something
	tree30.right = &tree70;

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.sumOfLeftLeaves(&tree1);
	Solution question2;
	question2.sumOfLeftLeaves(&tree1);

	return 0;
}
