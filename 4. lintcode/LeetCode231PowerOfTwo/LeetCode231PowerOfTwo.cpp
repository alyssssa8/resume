//https://leetcode.com/problems/power-of-two/description/
//Given an integer, write a function to determine if it is a power of two
//
//Example 1 :
//
//	Input : 1
//	Output : true
//	Explanation : 20 = 1
//	Example 2 :
//
//	Input : 16
//	Output : true
//	Explanation : 24 = 16
//	Example 3 :
//
//	Input : 218
//	Output : false
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

class Solution2 {
public:
	bool isPowerOfTwo(int n) {
		if (n == 1) {
			return true;
		}
		long long sum = 1;
		while (n> sum) {

			sum *= 2;
			if (sum == n) {
				return true;
			}
		}


		return false;

	}
};

class Solution3 {
public:
	bool isPowerOfTwo(int n) {
		if (n == 1) {
			return true;
		}
		int temp = 2;
		long long traverse = 1;
		while (traverse < n) {
			if (temp * traverse == n) {
				return true;
			}
			traverse = temp * traverse;
		}
		return false;
	}
};



class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n < 1) {
			return false;
		}
		while (n % 2 == 0) {  // 2 / 2 = 1;
			n /= 2;
		}

		return n == 1;
	}

};
int main()
{
	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.isPowerOfTwo(16);
	Solution question2;
	question2.isPowerOfTwo(128);

	return 0;
}