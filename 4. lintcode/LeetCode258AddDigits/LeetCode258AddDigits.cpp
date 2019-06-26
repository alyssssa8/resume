//https://leetcode.com/problems/add-digits/description/
//Given a non - negative integer num, repeatedly add all its digits until the result has only one digit.
//
//Example :
//
//	Input : 38
//	Output : 2
//	Explanation : The process is like : 3 + 8 = 11, 1 + 1 = 2.
//	Since 2 has only one digit, return it.
//	Follow up :
//Could you do it without any loop / recursion in O(1) runtime ?
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

class Solution3 {
public:
	int addDigits(int num) {
		return 1 + (num - 1) % 9; // math À„∑®°£
	}
};
//1 + (38-1) % 9 = 1 + 1 = 2
class Solution2 {
public:
	int addDigits(int num) {
		while (true) {
			int res = 0;
			while (num) {
				res += num % 10;
				num /= 10;
			}
			if (res < 10)
				return res;
			num = res;
		}
	}
};

//own
class Solution {
public:
    int addDigits(int num) {
        int temp = num;
        while (temp >= 10) {
            num = temp;
            temp = 0;
            while (num > 0) {
                temp += num % 10;
                num = num / 10;
            }
        }
        return temp;
    }
};

class Solution {
public:

	int addDigits(int num) {
		int res = 0;
		if (num < 10) {
			return num; //when in this step, will out of function. still go back to the previous layer's addDigits(res)
		}
		else {
			while (num) {
				res += num % 10;
				num = num / 10;
			}
		}

		return addDigits(res);
	}
};
void print(int n);
int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.addDigits(38);
	Solution2 question2;
	question2.addDigits(38);
	print(5);
	return 0;
}

// An example of tail recursive function
void print(int n)
{
	if (n < 0)  return;
	cout << " " << n;

	// The last executed statement is recursive call
	print(n - 1);
}
