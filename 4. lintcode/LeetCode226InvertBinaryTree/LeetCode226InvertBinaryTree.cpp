//https://leetcode.com/problems/invert-binary-tree/description
//Invert a binary tree.
//
//Example :
//
//	Input :
//
//	4
//	/ \
//	2     7
//	/ \ / \
//	1   3 6   9
//	Output:
//
//4
/// \
//7     2
/// \ / \
//9   6 3   1
//Trivia:
//This problem was inspired by this original tweet by Max Howell :
//
//Google: 90 % of our engineers use the software you wrote(Homebrew), but you can¡¯t invert a binary tree on a whiteboard so f*** off.
//


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


class Solution2 {
public:
	TreeNode * invertTree(TreeNode* root) {
		if (nullptr == root) return root;

		queue<TreeNode*> myQueue;   // our queue to do BFS
		myQueue.push(root);         // push very first item - root

		while (!myQueue.empty()) {    // run until there are nodes in the queue 

			TreeNode *node = myQueue.front();  // get element from queue
			myQueue.pop();                     // remove element from queue

			if (node->left != nullptr) {         // add left kid to the queue if it exists
				myQueue.push(node->left);
			}

			if (node->right != nullptr) {        // add right kid 
				myQueue.push(node->right);
			}

			// invert left and right pointers      
			TreeNode* tmp = node->left;
			node->left = node->right;
			node->right = tmp;

		}

		return root;
	}
};

class Solution {
public:
	TreeNode * invertTree(TreeNode* root) {
		if (root == NULL) {
			return NULL;
		}
		TreeNode* temp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(temp);
		return root;

	}
};

int main()
{

	TreeNode tree1(4);
	TreeNode tree2(2);
	TreeNode tree3(7);
	TreeNode tree4(1);
	TreeNode tree5(3);
	TreeNode tree6(6);
	TreeNode tree7(9);

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


	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.invertTree(&tree1);
	Solution question2;
	question2.invertTree(&tree1);

	return 0;
}