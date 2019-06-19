

//https://leetcode.com/problems/missing-number/description/
//https://www.youtube.com/watch?v=z0p_FBatGWM
//https://zxi.mytechroad.com/blog/math/leetcode-268-missing-number/
//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//
//Example 1 :
//
//	Input : [3, 0, 1]
//	Output : 2
//	Example 2 :
//
//	Input : [9, 6, 4, 2, 3, 5, 7, 0, 1]
//	Output : 8
//	Note :
//	Your algorithm should run in linear runtime complexity.Could you implement it using only constant extra space complexity ?
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
#include<numeric>
using namespace std;
//1 ^ 3 = 1 ^ 011 (in binary) = 001 ^ 011 (binary)
//so the src(001) will be inverted in the 0th bit and 2 bit(because 101).
//so 001 ^ 011 = 010 -> 1(inverted)0 (same)0 (inverted)
//(3 *4) /  2 = 6
// Author: Zhonghua Xi (huahua)
class Solution {
public:


	// Solution 2: XOR
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int x = 0;
		for (int i = 0; i < n; ++i)  // if Input: [3,0,1] 
			// start at 1 because 
			x = x ^ (i + 1) ^ nums[i];  // 0 ^ 1 ^ 3// 2 ^ 2 ^ 0// 0 ^ 3 ^ 1
			// i + 1 which escaped the 0, which means every keep the same, do not need to use that.
			// also the number will be even as nums.size();

		return x;
	}
};

//use this one
class Solution4 {
public:
	int missingNumber(vector<int>& nums) {

		int sum = nums.size() * (nums.size() + 1) / 2;
		for (int i = 0; i < nums.size(); i++) {
			sum -= nums[i];
		}
		return sum;
	}
};
//26%
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        sort(nums.begin(), nums.end());
        for (; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return i;

    }
};

class Solution2 {
public:
	int missingNumber(vector<int>& nums) {

		int ans = nums.size()*(nums.size() + 1) / 2 - accumulate(nums.begin(), nums.end(), 0); // will return 0 if missing 0's.
		return ans;

	}
};

int main()
{
	vector<int>nums({ 3,0,1 });
	Solution question;
	question.missingNumber(nums);

	return 0;
}