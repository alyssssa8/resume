//A peak element is an element that is greater than its neighbors.
//Given an input array where num[i] != num[i+1], find a peak element and return its index.
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that num[-1] = num[n] = -infinite.
//
//For example, in array[1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

//https://leetcode.com/problems/find-peak-element/description/
//http://www.lintcode.com/en/problem/find-peak-element/
//https://www.jiuzhang.com/solution/find-peak-element/







#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums);

class Solution {
public:
	int findPeakElement(vector<int>& nums) {

		int start = 0;
		int end = nums.size() - 1;
		int mid;
		while (start < end) {
			mid = start + (end - start) / 2;
			if (nums[mid]<nums[mid + 1]) {
				start = mid + 1;
			}
			else {
				end = mid - 1 ;
			}
		}

		return start;
	}
};
//only one with < and + 1, not -1. ***
// [1](if use "<=", do not have "mid + 1", [1, 2], [2, 1], [1,2,3,1], [5,6,4](start is "5", mid is "6" will miss the "6" if with end = mid - 1;

class Solution2 {
public:
	int findPeakElement(vector<int>& nums) {
		int start = 0;
		int end = nums.size() - 1;
		while (start < end) // if nums:[1], will not have mid + 1;
		{
			int mid = start + (end - start) / 2; //forgot "/2"
			if (nums[mid] <= nums[mid + 1])
			{
				start = mid + 1;
			}
			else
			{
				end = mid; // if (end = mid - 1):[1,2,1,3,5,6,4] . until [5,6,4],  which is index 4. 
			}
		}
		return start;
	}
};

int main()
{

    //vector<int> nums({ 1,2,1,1,9,6,7,8,9 });
    //vector<int> nums({ 9,2,3,5,4,4,3,2});
	vector<int> nums({ 1,2,1,3,5,6,4 });
    findPeakElement(nums);
	Solution question;
	question.findPeakElement(nums);
	return 0;
}
int findPeakElement(vector<int>& nums) {

    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = (right + left) / 2;

        if (nums[mid] < nums[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return right;
}