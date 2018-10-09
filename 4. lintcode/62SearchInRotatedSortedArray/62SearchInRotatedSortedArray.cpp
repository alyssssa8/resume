//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//
//https://leetcode.com/problems/search-in-rotated-sorted-array/description/
//http://www.lintcode.com/en/problem/search-in-rotated-sorted-array/
//https://www.jiuzhang.com/solution/search-in-rotated-sorted-array/



#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;
int search(vector<int>& nums, int target);



class Solution {
public:
	int search(vector<int>& nums, int target) {

		int start = 0;
		int end = nums.size() - 1;

		while (start <= end) {
			int mid = start + (end - start) / 2;

			if (nums[mid] == target) {
				return mid;
			}
			if (nums[mid]<nums[start]) {

				if (target == nums[end]) { // deal with [3, 5, 1]
					return end;
				}
				else if (target >  nums[mid] && target < nums[end]) {
					start = mid + 1;
				}
				else {
					end = mid - 1;
				}
			}
			else if (nums[mid]> nums[end]) {

				if (target < nums[mid] && target >= nums[start]) { //could use both way as the above.  added a = at this line. 
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
			else {
				if (target == nums[mid]) {
					return mid;
				}
				if (target < nums[mid]) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}

		}
		return -1;
	}
};


int main()
{
	vector<int> nums({3,5,1 });
	int target = 0;
	search(nums, target);
	Solution question;
	question.search(nums, target);
//-----------------------------------------------

    return 0;
}



//
int search(vector<int>& nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (target == nums[mid])
            return mid;

        // there exists rotation; the middle element is in the left part of the array
        if (nums[mid] > nums[r]) {
            if (target < nums[mid] && target >= nums[l])
                r = mid - 1;
            else
                l = mid + 1;
        }

        // there exists rotation; the middle element is in the right part of the array
        else if (nums[mid] < nums[l]) {
            if (target > nums[mid] && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }

        // there is no rotation; just like normal binary search
        else {
            if (target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    return -1;
}