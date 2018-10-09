//https://leetcode.com/problems/power-of-four/description/
//
//Given an integer(signed 32 bits), write a function to check whether it is a power of 4.
//
//Example :
//	Given num = 16, return true.Given num = 5, return false.
//
//	Follow up : Could you solve it without loops / recursion ?
//
//	Credits :
//	Special thanks to @yukuairoy for adding this problem and creating all test cases.



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
	bool isPowerOfFour(int num) {
		if (num < 1) {
			return false;
		}

		while (num % 4 == 0) {
			num = num / 4;
		}
		return num == 1;
	}
};

// do not understand this method. 
class Solution {
public:
	bool isPowerOfFour(int num) {
		return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
	}
};

int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.isPowerOfFour(16);
	Solution question2;
	question2.isPowerOfFour(64);

	return 0;
}
