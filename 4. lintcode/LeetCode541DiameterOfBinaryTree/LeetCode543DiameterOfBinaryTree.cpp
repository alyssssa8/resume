

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
    int maxdiadepth = 0;

    int dfs(TreeNode* root) {
        if (root == NULL) return 0;

        int leftdepth = dfs(root->left);
        int rightdepth = dfs(root->right);

        if (leftdepth + rightdepth > maxdiadepth) maxdiadepth = leftdepth + rightdepth;
        return max(leftdepth + 1, rightdepth + 1);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        return maxdiadepth;
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

    vector<int>nums1({ 0 });
    vector<int>nums2({ 1 });
    Solution question;
    question.diameterOfBinaryTree(&tree1);
    /*   Solution question2;
       question2.merge(250);*/

    return 0;
}