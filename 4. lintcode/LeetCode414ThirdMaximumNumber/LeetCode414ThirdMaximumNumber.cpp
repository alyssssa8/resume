//https://leetcode.com/problems/third-maximum-number/description/
//
//Given a non - empty array of integers, return the third maximum number in this array.If it does not exist, return the maximum number.The time complexity must be in O(n).
//
//Example 1 :
//	Input : [3, 2, 1]
//
//	Output : 1
//
//	Explanation : The third maximum is 1.
//	Example 2 :
//	Input : [1, 2]
//
//	Output : 2
//
//	Explanation : The third maximum does not exist, so the maximum(2) is returned instead.
//	Example 3 :
//	Input : [2, 2, 3, 1]
//
//	Output : 1
//
//	Explanation : Note that the third maximum here means the third maximum distinct number.
//	Both numbers with value 2 are both considered as second maximum.
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
#include<numeric>
using namespace std;





class Solution2 {
public:
	int thirdMax(vector<int>& nums) {
		long long a, b, c;
		a = b = c = LLONG_MIN;
		for (auto num : nums) {
			if (num <= c || num == b || num == a) continue;
			c = num;
			if (c > b) swap(b, c);
			if (b > a) swap(a, b);
		}
		return c == LLONG_MIN ? a : c;
	}
};


// input [1,1,2];
class Solution {
public:
	int thirdMax(vector<int>& nums) {

		long long firstBig = LLONG_MIN,
			      secondBig = LLONG_MIN,
			      thirdBig = LLONG_MIN;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= thirdBig || nums[i] == secondBig || nums[i] == firstBig) {
				continue;
			} //*** for repeat input, then the max will be same as the repeat input. will not be LLONG_MIN
			thirdBig = nums[i];
			if (secondBig < thirdBig) {
				swap(secondBig, thirdBig);
			}
			if (firstBig <secondBig) {
				swap(firstBig, secondBig);
			}

		}
		return thirdBig == LLONG_MIN ? firstBig : thirdBig;
	}
};

int main()
{



	vector<int>nums({ 1, 1, 2});
	Solution question;
	int result = question.thirdMax(nums);


	return 0;
}