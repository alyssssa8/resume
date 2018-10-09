//
//https://leetcode.com/problems/valid-perfect-square/description/
//
//Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
//Note : Do not use any built - in library function such as sqrt.
//
//	Example 1 :
//
//	Input : 16
//	Returns : True
//	Example 2 :
//
//	Input : 14
//	Returns : False


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
	bool isPerfectSquare(int num) {

		long long start = 1, end = (num + 1) / 2; // type is long. 
		while (start <= end) {
			long long mid = start + (end - start) / 2;
			if (mid * mid == num) {
				return true;
			}
			if (mid * mid < num) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		return false;

	}
};
int main()
{
	vector<int>numbers{ 1,3,5,6 };
	int x = 5;


	Solution question;
	question.isPerfectSquare(4);
	Solution question2;
	question2.isPerfectSquare(x);

	return 0;
}