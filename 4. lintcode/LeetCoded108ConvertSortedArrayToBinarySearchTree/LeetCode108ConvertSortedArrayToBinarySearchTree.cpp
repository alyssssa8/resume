//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
//
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example:
//
//Given the sorted array : [-10, -3, 0, 5, 9],
//
//One possible answer is : [0, -3, 9, -10, null, 5], which represents the following height balanced BST :
//
//0
/// \
//- 3   9
///   /
//-10  5
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

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// -10,-3,0,5,9 
class Test2 {
public:

	TreeNode * sortedArrayToBST(vector<int>& nums) {
		TreeNode* root = dfs(nums, 0, nums.size() - 1);
		return root;
	}



	TreeNode* dfs(vector<int>& nums, int startIndex, int endIndex)
	{

		if (startIndex <= endIndex) {
			int  mid = startIndex + (endIndex - startIndex) / 2;
			TreeNode* newNode = new TreeNode(nums[mid]);
			newNode->left = dfs(nums, startIndex, mid - 1);
			newNode->right = dfs(nums, mid + 1, endIndex);
			return newNode;
		}
		else {
			return NULL;
		}


	}
};
class Test
{

public:
	TreeNode * sortedArrayToBST(vector<int>& nums)
	{

		TreeNode * ans;
		if (nums.size() == 0)
		{
			return  nullptr;
		}
		if (nums.size() == 1)
		{
			return new TreeNode(nums[0]);
		}
		int mid = nums.size() / 2;
		ans = new TreeNode(nums[mid]);
		vector<int> left(nums.begin(), nums.begin() + mid);
		vector<int> right(nums.begin() + mid + 1, nums.end());
		ans->left = sortedArrayToBST(left);
		ans->right = sortedArrayToBST(right);

		return ans;
		


	}
};



class Solution 
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
         TreeNode* root;
         if (nums.size() == 0)
		 {
			 return nullptr;
		 }
		 if (nums.size() == 1)
		 {
			 return new TreeNode(nums[0]);
		 }
         int m = nums.size() / 2;
         root = new TreeNode(nums[m]);
		 
		 //vector<int> nums1,nums2;
		 vector<int> nums1(nums.begin(),nums.begin()+m);     
         vector<int> nums2(nums.begin()+m+1,nums.end());//skip the node
         //nums1.assign(nums.begin(), nums.begin() + m);
         //nums2.assign(nums.begin() + m+1, nums.end());
         //auto nums1=vector<int>(nums.begin(),nums.begin()+m);     
         //auto nums2=vector<int>(nums.begin()+m+1,nums.end());
		 root->left = sortedArrayToBST(nums1);
		 root->right = sortedArrayToBST(nums2);
		 return root;
    }
};
class Solution2 {
public:

	TreeNode * sortedArrayToBST(vector<int>& nums) {
		TreeNode* root = buildTree(nums, 0, nums.size() - 1);
		return root;
	}
	// partition the "nums" by two at every node of the tree and build downwards recursively.
	TreeNode* buildTree(vector<int>& nums, int startIndex, int endIndex)
	{
		if (startIndex > endIndex)
		{
			// elements that can be used in the indices of range [start,end] are exhausted.
			return NULL;
		}
		else
		{
			// pick the middle of array as the root of subtree.
			int mid = (startIndex + endIndex) / 2.0;
			TreeNode* newNode = new TreeNode(nums[mid]);

			// build the left and right subtrees recursively,
			// by partitioning the array into two.
			newNode->left = buildTree(nums, startIndex, mid - 1);
			newNode->right = buildTree(nums, mid + 1, endIndex);
			return newNode;
		}
	}
};
int main()
{
    int a = 'a';
    cout << a << endl;
	vector<int> nums{ -10,-3,0,5,9 };
	Solution question;	
	question.sortedArrayToBST(nums);
	Solution question2;
	question2.sortedArrayToBST(nums);

	Test question3;
	question3.sortedArrayToBST(nums);
	Test2 question4;
	question4.sortedArrayToBST(nums);
	return 0;
}

