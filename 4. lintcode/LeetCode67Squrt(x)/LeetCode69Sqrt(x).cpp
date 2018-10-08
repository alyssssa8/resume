//https://leetcode.com/problems/sqrtx/description/
//Implement int sqrt(int x).
//
//Compute and return the square root of x, where x is guaranteed to be a non - negative integer.
//
//Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
//Example 1:
//
//Input: 4
//	Output : 2
//	Example 2 :
//
//	Input : 8
//	Output : 2
//	Explanation : The square root of 8 is 2.82842..., and since
//	the decimal part is truncated, 2 is returned.


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
	int mySqrt(int x) {
		long long start = 1, end = x;
		while (start <= end) {
			long long mid = start + (end - start) / 2;
			cout << mid << endl;
			if (mid * mid == x) {
				return mid;
			}
			else if (mid * mid > x) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		cout << "________________________________" << endl;
		return end;// overflow?
	}
};

//[1]
class Solution2 {
public:
	int mySqrt(int x) {
		//long long is int64, can hold 64 bit = 8 byte number, it will have int32 *int32 computation.  
		//for example: 10000000 * 10000000 will more the int32, it is int64. 
		long long lo = 1, hi = x, mid = 0; // type is long. not int
		//if lo == 1,  hi = hi/2, if x == 1, hi = 0 and hi more than low. will return 0.  
		// if lo == 0 and hi == 0 mid will == 0, 0*0 = 0< x, start = 0 + 1 = 1, hi still is 0.

		while (lo <= hi)
		{
			mid = lo + (hi - lo) / 2;
			cout << mid << endl;
			//cout << lo << " , " << hi << " , " << mid << endl;
			if (mid * mid == x)
			{
				return mid;
			}

			else if (mid * mid < x)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
		return hi;   // lo


	}
};

int main()
{
	vector<int>numbers{ 1 };
	int x = 2147365599;
	//int x = 17;
	Solution question;
	int result = question.mySqrt(4);
	Solution2 question2;
	question2.mySqrt(x);


	return 0;
}