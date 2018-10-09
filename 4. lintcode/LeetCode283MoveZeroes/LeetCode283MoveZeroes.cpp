//https://leetcode.com/problems/move-zeroes/description/
//
//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//Example :
//
//	Input : [0, 1, 0, 3, 12]
//	Output : [1, 3, 12, 0, 0]
//	Note :
//
//	You must do this in - place without making a copy of the array.
//	Minimize the total number of operations.
//
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

class Solution {
public:
	void moveZeroes(vector<int>& nums) {

		int newIndex = 0;
		for (int i = 0; i <nums.size(); i++) {
			if (nums[i] != 0) {
			
				nums[newIndex] = nums[i];
				newIndex++;
			}
		}

		for (int i = newIndex; i <nums.size(); i++) {
			nums[i] = 0;
		}


	}
};


class Solution {
public:
	void moveZeroes(vector<int>& nums) { // assume that the number are in order with out zero.

		int orgin = nums.size();
		int newIndex = 0;
		int numberOfZero = 0;

		for (int i = 0; i < orgin; i++)
		{
			if (nums[i] == 0) {
				numberOfZero++;
			}
			else {
				nums[newIndex] = nums[i];
				newIndex++;
			}
		}

		for (int i = 0; i < numberOfZero; i++) {
			nums[newIndex] = 0;
			newIndex++;
		}

	}
};
int main()
{

	vector<int> nums({ 0,1,0,3,12 });
	Solution question;
	question.moveZeroes(nums);

	return 0;
}