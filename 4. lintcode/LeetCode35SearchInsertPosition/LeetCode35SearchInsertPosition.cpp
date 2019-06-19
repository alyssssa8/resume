//https://leetcode.com/problems/search-insert-position/description/
//
//Given a sorted array and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Example 1:
//
//Input: [1, 3, 5, 6], 5
//	Output : 2
//	Example 2 :
//
//	Input : [1, 3, 5, 6], 2
//	Output : 1
//	Example 3 :
//
//	Input : [1, 3, 5, 6], 7
//	Output : 4
//	Example 4 :
//
//	Input : [1, 3, 5, 6], 0
//	Output : 0



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
class Test {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {




	}
};



// use this one
//1,3,5,6 insert 1
//1,3,5,6, insert  7
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		int start = 0;
		int end = nums.size() - 1;

		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] > target)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		return start;
	}
};
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		int start = 0;
		int end = nums.size() - 1;

		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (target > nums[mid])
			{
				start = mid + 1;
			}
			else if (target == nums[mid])
			{
				return mid;
			}
			else
			{
				end = mid - 1;
			}


		}
		return start;

	}
};
int main()
{
	vector<int>nums{ 1,3,5,6 };
	int target = 5;
	

	Solution question;
	question.searchInsert(nums, target);
	Test question2;
	question2.twoSum(nums, target);

	return 0;
}