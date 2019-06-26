//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
//
//Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
//
//You need to find the shortest such subarray and output its length.
//
//Example 1:
//Input: [2, 6, 4, 8, 10, 9, 15]
//	Output : 5
//	Explanation : You need to sort[6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//	Note :
//	Then length of the input array is in range[1, 10, 000].
//	The input array may contain duplicates, so ascending order here means <= .


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
///[1,2,3,4]
// use this one!
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1, max = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (max > nums[i]) {
                if (start == -1) {
                    start = i - 1;
                }
                while (start - 1 >= 0 && nums[start - 1] > nums[i]) {
                    start--;
                }
                end = i;
            }
            else {
                max = nums[i];
            }
        }
        return end - start + 1;
    }
};


// 1,3,2,2,2 // so need to compare with the max, not nums[i - 1]
// 1,2,3,3,3
class Solution2 {
public:
	int findUnsortedSubarray(vector<int>& nums) {

		stack<int> st;
		int L = nums.size() + 1, R = -1;
		for (int i = 0; i < nums.size(); i++) {
			int n = nums[i];
			while (!st.empty() && nums[st.top()] < n) {
				L = min(L, st.top());
				st.pop();
			}
			st.push(i);
		}
		if (L == nums.size() + 1 || nums.size() == 0) {
			return 0;
		}
		for (; st.empty() == false; st.pop());

		for (int i = nums.size() - 1; i >= 0; i--) {
			int n = nums[i];
			while (!st.empty() && nums[st.top()] < n) {
				R = max(R, st.top());
				st.pop();
			}
			st.push(i);
		}
		return R - L + 1;
	}
};
int main()
{

	vector<int>nums({ 2, 6, 4, 8,1, 10, 9,15});
	//vector<int>nums({ 1, 2, 3,1 });
	Solution question;
	question.findUnsortedSubarray(nums);
	Solution question2;
	question2.findUnsortedSubarray(nums);

	return 0;
}

