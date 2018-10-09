//https://leetcode.com/problems/factorial-trailing-zeroes/description/
//
//Given an integer n, return the number of trailing zeroes in n!.
//
//Example 1 :
//
//	Input : 3
//	Output : 0
//	Explanation : 3!= 6, no trailing zero.
//	Example 2 :
//
//	Input : 5
//	Output : 1
//	Explanation : 5!= 120, one trailing zero.
//	Note : Your solution should be in logarithmic time complexity.



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

//n = 5, 10, 15,20, 25,
class Solution {
public:
	int trailingZeroes(int n) {
		int result = 0;
		for (long long i = 5; n / i > 0; i *= 5) {
			result += (n / i);
		}
		return result;

	}
};


int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.trailingZeroes(30);
	Solution question2;
	question2.trailingZeroes(120);

	return 0;
}
