//leetcode
//http://www.lintcode.com/en/problem/binary-tree-paths/
//https://leetcode.com/problems/binary-tree-paths/description/
//https://www.jiuzhang.com/solution/binary-tree-paths/
//Given a binary tree, return all root - to - leaf paths.
//
//For example, given the following binary tree :
//
//    1
//   / \
//  2    3
//  /\
// 5
//All root - to - leaf paths are :
//
//["1->2->5", "1->3"]

#include <iostream>
#include <math.h>
#include <algorithm> 
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int, int>m;
        stack<int>s;
        for (auto x : nums) {
            while (!s.empty() && s.top() < x) {
                m[s.top()] = x;
                s.pop();
            }
            s.push(x);
        }
        for (auto& x : findNums) {
            if (m.count(x)) {
                x = m[x];
            }
            else {
                x = -1;
            }
        }
        return findNums;
    }
};


int main()
{
    vector<int> nums1({ 1,2,1 });
    vector<int> nums2({ 4,1,2 });
    Solution s; // instance of solution
    s.nextGreaterElement(nums1, nums2);



    return 0;
}
