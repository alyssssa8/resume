//https://leetcode.com/problems/palindrome-number/description/
//Assume we are dealing with an environment which could only store integers within the 32 - bit signed integer range : [−231, 231 − 1].For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//
//Determine whether an integer is a palindrome.An integer is a palindrome when it reads the same backward as forward.
//
//Example 1:
//
//Input: 121
//	Output : true
//	Example 2 :
//
//	Input : -121
//	Output : false
//	Explanation : From left to right, it reads - 121. From right to left, it becomes 121 - .Therefore it is not a palindrome.
//	Example 3 :
//
//	Input : 10
//	Output : false
//	Explanation : Reads 01 from right to left.Therefore it is not a palindrome.
//	Follow up :
//
//	   Coud you solve it without converting the integer to a string ?


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


class Solution3 {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        else {
            string temp = to_string(x);
            int start = 0;
            int end = temp.size() - 1;
            while (start < end) {
                if (temp[start] != temp[end]) {
                    return false;
                }
                start++;
                end--;
            }
        }
        return true;
    }
};
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0)) { //10
			return false;
		}
		int sum = 0;
		while (x>sum)//121  // 1,12
		{
			sum = sum * 10 + x % 10;
			x = x / 10;
		}
		return (x == sum) || (x == sum / 10); //if input is 10, sum = 0, x = 1 | sum = 1, x = 0 | sum / 10 = 1 /10 = 0  will return true. 
	}
};

class Solution2 {
public:
	bool isPalindrome(int x) {
		string str1 = to_string(x);
		string str2 = to_string(x);
		reverse(str1.begin(), str1.end());
		if (str1 == str2) {
			return true;
		}
		return false;
	}
};

int main()
{


	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.isPalindrome(10);
	Solution question2;
	question2.isPalindrome(250);

	return 0;
}
