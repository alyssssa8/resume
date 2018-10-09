
//https://www.jiuzhang.com/solutions/subtree-with-maximum-average/
//Given a binary tree, find the subtree with maximum average.Return the root of the subtree.
//
//Example
//Given a binary tree :
//        1
//       / \
//    - 5   11
//    / \   / \
//    1  2 4 - 2
//return the node 11.
//1-5+11=7
//-5+1+2=2
//11+4-2=13



#include "BinaryTree.h"


#include <iostream>

#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include <vector>
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

class ResultType {
public:
    int sum, size;
    ResultType() :sum(0), size(0) {}
    ResultType(int _sum, int _size) : sum(_sum), size(_size) {}
};




class Test {
private: 
	TreeNode * ansNode = NULL;
	ResultType ansResult;

public:

	TreeNode* findSubtree2(TreeNode* root) {
		
		dfs(root);
		return ansNode;
	}

	ResultType dfs(TreeNode * root)
	{

		if (!root)
		{
			return ResultType();
		}
		ResultType left = dfs(root->left);
		ResultType right = dfs(root->right);

		ResultType tempResult = ResultType(left.sum + right.sum + root->val, left.size + right.size + 1);
		
		if (ansNode == NULL || tempResult.sum * ansResult.size >= tempResult.sum * ansResult.size)
		{
			ansResult = tempResult;
			ansNode = root;
		}
		return tempResult;

	}
};


class Solution {
public:   
    TreeNode* findSubtree2(TreeNode* root) {
        // Write your code here
        ResultType result = helper(root);
      /*
        cout << "this is the sum" << endl;
        cout << result.sum<< endl;
        cout << "this is the size" << endl;
        cout << result.size << endl;
*/
        return node;
    }
	// The function has a return type. you must return.
	// unless the return type is void
    ResultType helper(TreeNode* root) {
        if (root == NULL) {
            return ResultType();
        }
        ResultType left = helper(root->left);
        ResultType right = helper(root->right); // here uses the result of little cake. will be used by big cake

        ResultType result = ResultType(left.sum + right.sum + root->val,
            left.size + right.size + 1);
        /*cout << "this is the root " << endl;
        cout << root->val << endl;
        cout << "this is the sum" << endl;
        cout << result.sum << endl;
        cout << "this is the size" << endl;
        cout << result.size << endl;
        cout << "this is the sum" << endl;
        cout << data.sum << endl;
        cout << "this is the size" << endl;
        cout << data.size << endl;
        cout << " this is the node value" << endl;
        cout << "_____________________________________" << endl;
*/
        if (node == NULL || result.sum * data.size >= data.sum * result.size) {

            data = result;
            node = root;
        }
       /* cout << "this is the sum" << endl;
        cout << result.sum << endl;
        cout << "this is the size" << endl;
        cout << result.size << endl;
        cout << "this is the sum" << endl;
        cout << data.sum << endl;
        cout << "this is the size" << endl;
        cout << data.size << endl;
        cout << " this is the node value" << endl;
        cout << node->val << endl;
        cout << "___________________________________________________________________" << endl;*/
        return result;
    }

private:
    TreeNode * node = NULL;
    ResultType data;
};


void print(TreeNode *tree1);
int main()
{
    IntBinaryTree tree;
    
    //cout << "Inserting nodes. " << endl;
   
   /* tree.insertNode(1);
    tree.insertNode(-5);
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(4);
    tree.insertNode(-2);*/
   

    TreeNode tree1(100);
    TreeNode tree2(-500);
    TreeNode tree3(1100);
    TreeNode tree4(100);
    TreeNode tree5(200);
    TreeNode tree6(400);   
    TreeNode tree7(-200);

    tree1.left = &tree2; // & to get the address of something
    tree1.right = &tree3;
    tree2.left = &tree4; // & to get the address of something
    tree2.right = &tree5;
    tree3.left = &tree6; // & to get the address of something
    tree3.right = &tree7;
    //findSubtree2(tree1); // this method belongs to the class. So you need an instance of the class to call the function
    //print(&tree1);
    Solution s; // instance of solution
    TreeNode *result =s.findSubtree2(&tree1);
    
    cout << " the final result " << result->val;


    return 0;
}

void print( TreeNode *tree1)
{
    if (tree1 != NULL)
    {        
        print(tree1->left);
        cout << tree1->val<<endl;
        print(tree1->right);
    }
   
            
}