//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array.
//
//http://www.lintcode.com/en/problem/find-minimum-in-rotated-sorted-array/
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
//https://www.jiuzhang.com/solution/find-minimum-in-rotated-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums);
class test {
public:
	int findMin(vector<int>& nums) {
		int start = 0;
		int end = nums.size()-1;

		
		while (start < end)
		{
			int mid = start + (end - start) / 2;

			if (nums[mid] > nums[end])
			{
				start = mid + 1;
			}
			else
			{
				end = mid;
			}
			return nums[start];

		}


	}
};

class Solution {
public:
	int findMin(vector<int>& nums) {

		int start = 0;
		int end = nums.size() - 1;
		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] > nums[end]) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		return nums[start];

	}
};


// [2,1],[3,1,2]
class Solution2 {
public:
	int findMin(vector<int>& nums) {

		int start = 0;
		int end = nums.size() - 1;
		int mid = 0;
		int target = nums[nums.size() - 1]; // end is the value to compare.
		while (start <= end)
		{
			mid = start + (end - start) / 2; //fogot the "int" type
			// if change target to end£¬ when start == end, end will --, will nit min
			// or [3,1,2] if mid = 1, end --, target should not 3
			if (nums[mid] <= target)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}

		}

		return nums[start]; //be careful the return value


	}
};



int main()
{
    vector<int> nums({3, 1, 2});
    findMin(nums);

	Solution question;
	question.findMin(nums);
	test question2;
	question2.findMin(nums);
    return 0;
}
int findMin(vector<int>& nums)
{
    int start = 0;
    int end = nums.size()-1;
    int target = nums[end];
     
    while (start + 1 < end)
    {
       int  mid = start + (end - start) / 2;
       if (nums[mid] <= target)
       {
           end = mid;
       }
       else
       {
           start = mid;
       }
    }    
    if (nums[start] <= target)
    {
        return nums[start];
    }
    else
    {
        return nums[end];
    }
    
}