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
public:
    void getResult(TreeNode *node, double target, double &result) {
        if (!node) {
            return;
        }
        if (abs((double)node->val - target) < abs(target - result)) {
            result = (double)node->val;
        }
        if ((double)node->val > target) {
            getResult(node->left, target, result);
        }
        else if ((double)node->val < target) {
            getResult(node->right, target, result);
        }
    }

    int closestValue(TreeNode* root, double target) {
        double result = (double)root->val;
        getResult(root, target, result);
        return (int)result;
    }
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int result = root->val;
        while (root) {
            if ((double)root->val == target) {
                return root->val;
            }
            if (abs((double)root->val - target) < abs(result - target)) {
                result = root->val;
            }
            if (root->val > target) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return result;
    }
};



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
    s.closestValue(&tree1,4);
    // << "the out put node " << endl;

    //vector<string>::iterator iter;
    //for (iter = result.begin(); iter != result.end(); iter++)
    //{
    //    cout << *iter << endl; // if vector is a struct, (*iter).member or iter->member
    //}
   /* Solution question;
    question.binaryTreePaths(&tree1);
*/


    return 0;
}
