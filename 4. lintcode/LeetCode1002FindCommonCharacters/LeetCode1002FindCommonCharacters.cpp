//https://leetcode.com/problems/array-partition-i/description/
//Given an array of 2n integers, your task is to group these integers into n pairs of integer, say(a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
//
//Example 1 :
//	Input : [1, 4, 3, 2]
//
//	Output : 4
//	Explanation : n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
//	Note :
//	n is a positive integer, which is in the range of[1, 10000].
//	All the integers in the array will be in the range of[-10000, 10000].


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

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        if (A.empty()) {
            return {};
        }
        int count[26] = { 0 };
        for (char ch : A[0]) {
            count[ch - 'a']++;
        }
        for (int i = 1; i < A.size(); i++) {
            int c[26] = { 0 };
            for (auto ch : A[i]) {
                c[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                count[i] = min(count[i], c[i]);
            }
        }
        vector<string> ret;
        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                char ch = 'a' + i;
                ret.push_back(string(1, ch));
                count[i]--;
            }
        }
        return ret;
    }
};

int main()
{

    vector<string>nums({ "bella","label","roller" });

    Solution question;
    question.commonChars(nums);

    return 0;
}


