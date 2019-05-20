//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
//
//Given a binary search tree(BST), find the lowest common ancestor(LCA) of two given nodes in the BST.
//
//According to the definition of LCA on Wikipedia : ¡°The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants(where we allow a node to be a descendant of itself).¡±
//
//Given binary search tree : root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5]
//
//_______6______
/// \
//___2__          ___8__
/// \ / \
//0      _4       7       9
/// \
//3   5
//Example 1:
//
//Input: root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5], p = 2, q = 8
//	Output : 6
//	Explanation : The LCA of nodes 2 and 8 is 6.
//	Example 2 :
//
//	Input : root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5], p = 2, q = 4
//	Output : 2
//	Explanation : The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself
//	according to the LCA definition.



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
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		TreeNode *r;
		if (p->val > q->val) {
			swap(p, q);
		}
		r = root;

		while (r->val < p->val || r->val > q->val) {
			while (r->val < p->val) {  // 6 < 8
				r = r->right;
			}

			while (r->val > q->val) { // 6 > 2
				r = r->left;
			}
		}

		return r;

	}
};

class Solution {
private:
	TreeNode * ans; 
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val < q->val) {
			dfs(root, p, q);
		}
		else {
			dfs(root, q, p);
		}
		return ans;

	}

	void dfs(TreeNode* root, TreeNode* p, TreeNode* q) { // if do not return void, every dfs will need to have a  return value
		if (p->val <= root->val && q->val >= root->val) {
			ans = root;
			return;
		}
		else if (p->val < root->val && q->val < root->val) {
			dfs(root->left, p, q);
		}
		else if (p->val > root->val && q->val > root->val) {
			dfs(root->right, p, q);
		}
	}
};

// 3,5

int main()
{


	TreeNode tree1(6);
	TreeNode tree2(2);
	TreeNode tree3(8);
	TreeNode tree4(0);
	TreeNode tree5(4);
	TreeNode tree6(7);
	TreeNode tree7(9);

	TreeNode tree8(3);
	TreeNode tree9(5);


	TreeNode tree30(2);
	TreeNode tree40(8);
	TreeNode tree50(5);
	TreeNode tree60(6);
	TreeNode tree70(7);


	tree1.left = &tree2; // & to get the address of something
	tree1.right = &tree3;
	tree2.left = &tree4; // & to get the address of something
	tree2.right = &tree5;
	tree3.left = &tree6; // & to get the address of something
	tree3.right = &tree7;

	tree5.left = &tree8;
	tree5.right = &tree9;

	

	Solution question;
	question.lowestCommonAncestor(&tree1, &tree30,&tree40);
	Solution question2;
	question2.lowestCommonAncestor(&tree1, &tree30, &tree40);

	return 0;
}