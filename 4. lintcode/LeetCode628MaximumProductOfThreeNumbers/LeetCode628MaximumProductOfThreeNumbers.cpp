//https://leetcode.com/problems/maximum-product-of-three-numbers/description/
//Given an integer array, find three numbers whose product is maximum and output the maximum product.
//
//Example 1 :
//	Input : [1, 2, 3]
//	Output : 6
//	Example 2 :
//	Input : [1, 2, 3, 4]
//	Output : 24
//	Note :
//	The length of the given array will be in range[3, 104] and all elements are in the range[-1000, 1000].
//	Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
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
class  Solution2 {
public:
	int maximumProduct(vector<int>& nums) {

		int min1 = INT_MAX, min2 = INT_MAX;
		int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
		for (int n : nums) {
			if (n <= min1) {
				min2 = min1;
				min1 = n;
			}
			else if (n <= min2) {     // n lies between min1 and min2
				min2 = n;
			}
			if (n > max1) {            // n is greater than max1, max2 and max3
				max1 = n;
			}
			if (max1>max2) {
				swap(max1, max2);
			}
			if (max2>max3) {
				swap(max2, max3);

			}
		}
		return max(min1 * min2 * max1, max1 * max2 * max3);
	}
};

class  Solution {
public:
	int maximumProduct(vector<int>& nums) {

		int min1 = INT_MAX, min2 = INT_MAX;
		int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
		for (int n : nums) {
			if (n < min1) {
				min1 = n;
			}
			if (min1 < min2) {
				swap(min1, min2);
			}

			if (n > max1) {            // n is greater than max1, max2 and max3
				max1 = n;
			}
			if (max1>max2) {
				swap(max1, max2);
			}
			if (max2>max3) {
				swap(max2, max3);

			}
		}
		return max(min1 * min2 * max3, max1 * max2 * max3);
	}
};


class  Solution3 {
public:
	int maximumProduct(vector<int>& nums) {

		int min1 = INT_MAX, min2 = INT_MAX;
		int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
		for (int n : nums) {
			if (n <= min1) {
				min2 = min1;
				min1 = n;
			}
			else if (n <= min2) {     // n lies between min1 and min2
				min2 = n;
			}
			if (n >= max1) {            // n is greater than max1, max2 and max3
				max3 = max2;
				max2 = max1;
				max1 = n;
			}
			else if (n >= max2) {     // n lies betweeen max1 and max2
				max3 = max2;
				max2 = n;
			}
			else if (n >= max3) {     // n lies betwen max2 and max3
				max3 = n;
			}
		}
		return max(min1 * min2 * max1, max1 * max2 * max3);
	}
};




class Solution4 {
public:
	int maximumProduct(vector<int>& nums) {

		sort(nums.begin(), nums.end());
		return max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
	}
};
int main()
{

	vector<int>nums({ -15, -6, 8, 10 ,60 });
	Solution question;
	question.maximumProduct(nums);
	Solution2 question2;
	question2.maximumProduct(nums);

	return 0;
}

