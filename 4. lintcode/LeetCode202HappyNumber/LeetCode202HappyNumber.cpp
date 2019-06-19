//https://leetcode.com/problems/happy-number/description/
//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process : Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
//Example :
//
//	Input : 19
//	Output : true
//	Explanation :
//	12 + 92 = 82
//	82 + 22 = 68
//	62 + 82 = 100
//	12 + 02 + 02 = 1




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

#include <unordered_set>

//	12 + 92 = 82
//	82 + 22 = 68
//	62 + 82 = 100
//	12 + 02 + 02 = 1


class Solution {
public:
	int digitSquareSum(int n) {
		int sum = 0;
		int tmp;
		while (n) {
			tmp = n % 10;
			sum += tmp * tmp;
			n /= 10;
		}
		return sum;
	}

	bool isHappy(int n) {
		int slow = n;
		int fast = n;
		do {
			slow = digitSquareSum(slow);
			fast = digitSquareSum(fast);
			cout << "slow: " << slow << " fast1: " << fast;
			fast = digitSquareSum(fast);
			cout << " fast2:" << fast << endl;
			//if (fast == 1) return true; I added.
		} while (slow != fast);
		return slow == 1;
	}
};

class Solution2 {
public:
	bool isHappy(int n) {

		std::unordered_set<int> record;

		while (true) {

			int sum = 0;
			while (n > 0) {
				int digit = n % 10;
				n /= 10;
				sum += digit * digit;
			}

			if (sum == 1) {
				return true;
			}

			if (record.find(sum) != record.end()) {
				return false;
			}
			else {
				record.insert(sum);
			}

			n = sum;
		}

		return false;
	}
};
class Solution3 {
public:
	bool isHappy(int n) {

		int digit = 0;
		int loop = 10;
		while (loop) {
			int sum = 0;
			while (n > 0) {
				digit = n % 10;
				n = n / 10;
				sum += digit * digit;
			}
			n = sum;
			if (sum == 1) {
				return true;
			}

			loop--;
		}

		return false;
	}
};


//use this one
class Solution4 {
public:
    bool isHappy(int n) {
        int sum;
        int count = 0;
        while (n != 1) {
            sum = 0;
            while (n > 0) {
                sum += (n % 10)*(n % 10);
                n = n / 10;
            }
            n = sum;
            count++;
            if (count > 10) {
                return false;
            }
        }
        return n == 1;
    }
};
int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.isHappy(12);
	Solution2 question2;
	question2.isHappy(36);
	
	return 0;
}
