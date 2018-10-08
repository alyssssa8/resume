//https://leetcode.com/problems/add-strings/description/
//Given two non - negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
//Note :
//
//	The length of both num1 and num2 is < 5100.
//	Both num1 and num2 contains only digits 0 - 9.
//	Both num1 and num2 does not contain any leading zero.
//	You must not use any built - in BigInteger library or convert the inputs to integer directly.


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

//"17"+"28"

// 48 == '0'
class Solution2 {
public:
	string addStrings(string num1, string num2) {
		int i, j;
		int carry = 0;
		int tempInt1 = 0;
		int tempInt2 = 0;
		int tempSum = 0;
		string ans;
		for (i = num1.size() - 1, j = num2.size() - 1; i >= 0 && j >= 0; i--, j--) {
			tempInt1 = num1[i] - '0';
			tempInt2 = num2[j] - '0';
			tempSum = tempInt1 + tempInt2 + carry;
			carry = tempSum / 10;
			ans = to_string(tempSum % 10) + ans;
		}

		while (i >= 0) {
			tempInt1 = num1[i] - 48;
			tempSum = tempInt1 + carry;
			carry = tempSum / 10;
			ans = to_string(tempSum % 10) + ans;
			i--;
		}
		while (j >= 0) {
			tempInt2 = num2[j] - 48;
			tempSum = tempInt2 + carry;
			carry = tempSum / 10;
			ans = to_string(tempSum % 10) + ans;
			j--;
		}

		if (carry == 1) {
			ans = to_string(carry) + ans;
		}
		return ans;
	}
};

class Solution {
public:
	string addStrings(string num1, string num2) {
		string ret{};
		int d1, d2, carry{ 0 };
		for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0 || carry; ) {
			d1 = (i >= 0) ? num1[i--] - '0' : 0;
			d2 = (j >= 0) ? num2[j--] - '0' : 0;
			ret = (char)((d1 + d2 + carry) % 10 + '0') + ret;
			carry = (d1 + d2 + carry) / 10;
		}
		return ret;
	}
};

int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.addStrings("7", "8");
	Solution question2;
	question2.addStrings("dfs", "dfs");

	return 0;
}