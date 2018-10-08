//https://leetcode.com/problems/power-of-three/description/
//Given an integer, write a function to determine if it is a power of three.
//
//Example 1 :
//
//	Input : 27
//	Output : true
//	Example 2 :
//
//	Input : 0
//	Output : false
//	Example 3 :
//
//	Input : 9
//	Output : true
//	Example 4 :
//
//	Input : 45
//	Output : false



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
	bool isPowerOfThree(int n) {
		if (n < 1) {
			return false;
		}

		while (n % 3 == 0) {
			n /= 3;
		}

		return n == 1;
	}
};


class Solution {
public:
	bool isPowerOfThree(int n) { //0次方是让多项式的常数项是零次项。任何除0以外的数的0次方都是1 。如3的0次方是1，-1的0次方也是1，0的0次方没有意义。
		if (n == 1) {
			return true;
		}
		long long sum = 1;
		while (sum < n) {
			sum = sum * 3;
			if (sum == n) {
				return true;
			}
		}
		return false;
	}
};


int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.isPowerOfThree(9);
	Solution question2;
	question2.isPowerOfThree(27);

	return 0;
}
