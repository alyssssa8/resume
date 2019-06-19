//https://leetcode.com/problems/sqrtx/description/
//Implement int sqrt(int x).
//
//Compute and return the square root of x, where x is guaranteed to be a non - negative integer.
//
//Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
//Example 1:
//
//Input: 4
//	Output : 2
//	Example 2 :
//
//	Input : 8
//	Output : 2
//	Explanation : The square root of 8 is 2.82842..., and since
//	the decimal part is truncated, 2 is returned.


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
    int strStr(string haystack, string needle) {
        int haystackLength = haystack.length();
        int needleLength = needle.length();
        for (int i = 0; i <= haystackLength - needleLength; i++) { // can not use size here
            int j = 0;
            for (; j < needleLength; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needleLength) {
                return i;
            }
        }

        return -1;
    }
};

//own, too slow 5%
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() == 0 && needle.size() == 0) {
            return 0;
        }
        int ans = -1;
        for (int i = 0; i < haystack.size(); i++) {
            int needleCount = 0;
            int haystackCount = i;
            int count = 0;
            while (haystack[haystackCount] == needle[needleCount] && i < haystack.size() && needleCount < needle.size()) {
                count++;
                haystackCount++;
                needleCount++;
            }
            if (count == needle.size()) {
                ans = i;
                return ans;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int>numbers{ 1 };
    int x = 2147365599;
    //int x = 17;
    Solution question;
    int result = question.strStr("hello","ll");
   /* Solution2 question2;
    question2.mySqrt(x);*/

    
    return 0;
}