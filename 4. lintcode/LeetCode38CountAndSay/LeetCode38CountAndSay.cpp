//https://leetcode.com/problems/intersection-of-two-arrays/description/
//Given two arrays, write a function to compute their intersection.
//
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return[2].
//
//Note :
//	Each element in the result must be unique.
//	The result can be in any order.
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
#include<unordered_set>
#include <vector>
#include<set>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string res = "1";
        while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); i++) {
                int count = 1;
                while ((i + 1 < res.size()) && (res[i] == res[i + 1])) {
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};


int main()
{
    vector<int>nums1{ 1,2,2,1 };

    vector<int>nums2{ 2,2,1 };
    int newColor = 2;
    vector<int> ans(2, 3);
    /*Solution question;
    question.intersection(nums1,nums2);*/
  


    return 0;
}