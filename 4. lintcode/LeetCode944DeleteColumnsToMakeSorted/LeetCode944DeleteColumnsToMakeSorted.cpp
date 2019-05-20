//https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
//
//Let's call an array A a mountain if the following properties hold:
//
//A.length >= 3
//There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1]
//	Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1].


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

//own
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans = 0;
        for (int i = 0; i < A[0].size(); i++) {
            for (int j = 1; j < A.size(); j++) {
                if (A[j][i] < A[j - 1][i]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};


int main()
{
    vector<string>houses{ "cba", "daf","ghi"};

    vector<int>heaters{};


    Solution question;
    question.minDeletionSize(houses);

    return 0;
}