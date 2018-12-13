
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {


        if (t1 != NULL && t2 != NULL) {
            TreeNode* ans = new TreeNode(t1->val + t2->val);
            ans->left = mergeTrees(t1->left, t2->left);
            ans->right = mergeTrees(t1->right, t2->right);
            return ans;

        }
        else {
            return t1 ? t1 : t2;
        }

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

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.mergeTrees(&tree1, &tree10);
    //Solution2 question2;
    //question2.sortedArrayToBST(nums);

    return 0;
}