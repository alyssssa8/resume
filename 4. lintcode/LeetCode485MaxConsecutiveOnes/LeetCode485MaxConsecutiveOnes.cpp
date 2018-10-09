//https://leetcode.com/problems/max-consecutive-ones/description/
//Given a binary array, find the maximum number of consecutive 1s in this array.
//
//Example 1 :
//	Input : [1, 1, 0, 1, 1, 1]
//	Output : 3
//	Explanation : The first two digits or the last three digits are consecutive 1s.
//	The maximum number of consecutive 1s is 3.
//	Note :
//
//	The input array will only contain 0 and 1.
//	The length of input array is a positive integer and will not exceed 10, 000

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
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int curMax = 0, res = 0;
		for (auto num : nums) {
			if (num == 1) {
				curMax += 1;
			}
			else {
				res = max(curMax, res);
				curMax = 0;
				continue;
			}

		}
		return max(curMax, res);
	}
};

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int count = 0;
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				count++;
			}
			else {
				ans = max(ans, count);
				count = 0;
			}
		}
		return max(ans, count);
	}
};
int main()
{
	vector<int>nums({ 1,1,0,1,1,1 });
	Solution question;
	question.findMaxConsecutiveOnes(nums);


	return 0;
}