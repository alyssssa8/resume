//https://leetcode.com/problems/non-decreasing-array/description/
//
//Given an array with n integers, your task is to check if it could become non - decreasing by modifying at most 1 element.
//
//We define an array is non - decreasing if array[i] <= array[i + 1] holds for every i(1 <= i < n).
//
//	Example 1:
//Input: [4, 2, 3]
//	Output : True
//	Explanation : You could modify the first 4 to 1 to get a non - decreasing array.
//	Example 2 :
//	Input : [4, 2, 1]
//	Output : False
//	Explanation : You can't get a non-decreasing array by modify at most one element.
//	Note : The n belongs to[1, 10, 000].




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
public:											 // 4,2,3 x 
	bool checkPossibility(vector<int>& nums) {   // 2,4,1,3 v
		int count = 0;							 // 4,6,5,7 v
		for (int i = 1; i < nums.size(); i++) {  // 2,1     v
			if (nums[i] < nums[i - 1]) {	     // 5,6,2   v
				count++;						 
				if (count >= 2) {
					return false;
				}
				if (i - 2 < 0 || nums[i - 2] <= nums[i]) {
				// i-2 <0 which means when i == 1, like 4,2
				// || like 2,6,2,4   
				// 2,6,1,4				
				//1,3,2


                //1,6,2,4 
					nums[i - 1] = nums[i];
				}
                //8,9,2,
				else {
					nums[i] = nums[i - 1];
				}

			}
		}
		return true;
	}
};



int main()
{

	vector<int>nums({  2, 6, 1,4 });
	Solution question;
	question.checkPossibility(nums);
	Solution question2;
	question2.checkPossibility(nums);

	return 0;

}