//https://leetcode.com/problems/reverse-integer/description/
//Given a 32 - bit signed integer, reverse digits of an integer.
//
//Example 1 :
//
//	Input : 123
//	Output : 321
//	Example 2 :
//
//	Input : -123
//	Output : -321
//	Example 3 :
//
//	Input : 120
//	Output : 21
//	Note :
//	Assume we are dealing with an environment which could only store integers within the 32 - bit signed integer range : [−231, 231 − 1].For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.






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
	int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10) {
				return 0;
			}
			if (rev < INT_MIN / 10) {
				return 0;
			}
			rev = rev * 10 + pop;
		}
		return rev;
	}
}; 

class Solution {
public:
	int reverse(int x) {
		long long res = 0; // must long , not int. 
		while (x) { // pay attention on this part. 
			res = res * 10 + x % 10;  //-12 % 10 = -2//-1*10 + -1%10=-20+-1
			x /= 10; //-12 / 10 = -1
		}  // 2*-3 = =6
		//For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
		return (res<INT_MIN || res>INT_MAX) ? 0 : res;
	}
};

class Solution3 {
public:
    int reverse(int x) {
        int ans = 0;
        while (x > 0) {
            x /= 10;
            int temp = x % 10;
            ans = ans * 10 + temp;
        }
        return ans;
    }
};

int main()
{


	
	Solution3 question;
	question.reverse(123);
	Solution2 question2;
	question2.reverse(250);

	return 0;
}
