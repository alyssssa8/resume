//https://leetcode.com/problems/maximum-average-subarray-i/description/
//Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value.And you need to output the maximum average value.
//
//Example 1 :
//	Input : [1, 12, -5, -6, 50, 3], k = 4
//	Output : 12.75
//	Explanation : Maximum average is(12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
//	Note :
//	1 <= k <= n <= 30, 000.
//	Elements of the given array will be in the range[-10, 000, 10, 000].
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
class Solution2{
public:
	double findMaxAverage(vector<int>& nums, int k) {

		vector<int>sum(nums.size());
		sum[0] = nums[0];
		// get all the sum from each step. 
		for (int i = 1; i < nums.size(); i++) {
			sum[i] = sum[i - 1] + nums[i];
		}
		int res = sum[k - 1];// start at this point. 

		for (int i = k; i < nums.size(); i++) {
			res = max(res, (sum[i] - sum[i - k]));
		} // get the biggest sum, but did not divide by k
		res / k;				// == 12
		double ans = res; //double and int conversion //res = 51, ans = 51.000000000000000, == 12.750000000000000
		return ans / k;

	}
};
class Solution5 {
public:
	double findMaxAverage(vector<int>& nums, int k) {

		vector<int>sum(nums.size());
		sum[0] = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			sum[i] = sum[i - 1] + nums[i];
		}
		double res = sum[k - 1] * 1.0 / k;

		for (int i = k; i < nums.size(); i++) {
			res = max(res, (sum[i] - sum[i - k]) * 1.0 / k);
		}
		return res;

	}
};


class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int sum = 0;
		int ans = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (i == k - 1) {
				ans = max(ans, sum);
			}
			if (i >= k) {
				sum = sum - nums[i - k];
				ans = max(ans, sum);
			}

		}
		double res = ans;
		return res / k;
	}
};
// use *1.0 to change to double. 
class Solution3 {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int sum = 0;
		double ans = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (i == k - 1) {
				ans = max(ans, sum * 1.0 / k);
			}
			if (i >= k) {
				sum = sum - nums[i - k];
				ans = max(ans, sum * 1.0 / k);
			}

		}

		return ans;
	}
};
int main()
{

	vector<int>nums({ 1, 12, -5, -6, 50, 3});
	int k = 4;
	Solution2 question;
	question.findMaxAverage(nums, k);
	/*Solution question2;
	question2.findMaxAverage(nums, k);
*/
	return 0;
}

