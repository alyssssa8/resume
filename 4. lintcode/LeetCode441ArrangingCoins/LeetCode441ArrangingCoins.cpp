//https://leetcode.com/problems/arranging-coins/description/
//
//You have a total of n coins that you want to form in a staircase shape, where every k - th row must have exactly k coins.
//
//Given n, find the total number of full staircase rows that can be formed.
//
//n is a non - negative integer and fits within the range of a 32 - bit signed integer.
//
//Example 1:
//
//n = 5
//
//The coins can form the following rows :
//ก่
//ก่ ก่
//ก่ ก่
//
//Because the 3rd row is incomplete, we return 2.
//Example 2:
//
//n = 8
//
//The coins can form the following rows :
//ก่
//ก่ ก่
//ก่ ก่ ก่
//ก่ ก่
//
//Because the 4th row is incomplete, we return 3.

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
	int arrangeCoins(int n) {
		long start = 1;
	    long end = n; // type is long. when have "*" need to use long long
		while (start <= end)
		{
			long mid = start + (end - start) / 2;
			long result = (mid * (mid + 1)) / 2;
			if (result == n)  // be careful about the "=="
			{
				return mid;
			}
			else if (result < n)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}

		return end;
	}
};
class Solution2 {
public:
	int arrangeCoins(int n) {
		long low = 1, high = n;
		while (low < high) {
			long mid = low + (high - low + 1) / 2;

			if ((mid + 1) * mid / 2 <= n)
			{
				low = mid;
			}
			else
			{
				high = mid - 1;
			}
		}
		return high;
	}
};


class Solution {
public:
	int arrangeCoins(int n) {
		long long start = 1, end = n;
		while (start <= end) {
			long long mid = start + (end - start) / 2;
			if (mid * (mid + 1) / 2 == n) {
				return mid;
			}
			if (n < mid * (mid + 1)) {
				end = mid - 1;
			}
			else {
				start = mid + 1;

			}
		}

		return end;
	}
};
int main()
{
	int x = 5;


	Solution question;
	question.arrangeCoins(x);

	return 0;
}