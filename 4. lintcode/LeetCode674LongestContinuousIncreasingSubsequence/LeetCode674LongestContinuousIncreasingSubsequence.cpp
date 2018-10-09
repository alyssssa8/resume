//https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
//Given an unsorted array of integers, find the length of longest continuous increasing subsequence(subarray).
//
//Example 1 :
//	Input : [1, 3, 5, 4, 7]
//	Output : 3
//	Explanation : The longest continuous increasing subsequence is[1, 3, 5], its length is 3.
//	Even though[1, 3, 5, 7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
//	Example 2 :
//	Input : [2, 2, 2, 2, 2]
//	Output : 1
//	Explanation : The longest continuous increasing subsequence is[2], its length is 1.



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
class Solution4 {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int ans = 0;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] <= nums[i - 1]) {
				ans = max(ans, count);
				count = 0;
			}
			count++;
		}
		return max(ans, count);
	}
};


// 1, 3, 5, 4, 2, 3, 4 
class Solution3 {
public:
	int findLengthOfLCIS(vector<int>& nums) { //[1], [], [2,2,2]
		int ans = 0, anchor = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (i > 0 && nums[i - 1] >= nums[i]) {
				anchor = i;
			}


			ans = max(ans, i - anchor + 1);
		}
		return ans;
	}
}; 

class Solution2 {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int maxAns = 1;
		int count = 1;

		if (nums.size() == 0) {
			return 0;
		}
		for (int i = 1; i < nums.size(); i++) {

			if (nums[i] > nums[i - 1]) {
				count++;
			}

			else {
				maxAns = max(maxAns, count);
				count = 1;
			}

		}
		return max(maxAns, count);
	}
};





// be careful about [] and [1], empty and one value or [2,2,2]. 
class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int start = 0;
		int ans = 0;
		if (nums.size() == 1) {
			return 1;
		}
		for (int i = 1; i <nums.size(); i++) {
			if (nums[i] <= nums[i - 1]) {
				ans = max(ans, i - start);
				start = i;
			}
			if (i == nums.size() - 1) {
				ans = max(ans, i - start + 1);
			}

		}
		return ans;
	}
};

int main()
{

	vector<int>nums({ 1, 3, 5, 4, 7});
	//vector<int>nums({ 2, 2, 2, 2, 2 });
	Solution question;
	question.findLengthOfLCIS(nums);
	Solution question2;
	question2.findLengthOfLCIS(nums);

	return 0;
}