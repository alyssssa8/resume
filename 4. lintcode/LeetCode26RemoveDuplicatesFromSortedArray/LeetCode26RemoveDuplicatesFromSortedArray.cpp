//https://leetcode.com/problems/intersection-of-two-linked-lists/description/
//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists :
//
//A:          a1 ¡ú a2
//	¨K
//	c1 ¡ú c2 ¡ú c3
//	¨J
//	B : b1 ¡ú b2 ¡ú b3
//	begin to intersect at node c1.
//
//
//	Notes :
//
//	If the two linked lists have no intersection at all, return null.
//	The linked lists must retain their original structure after the function returns.
//	You may assume there are no cycles anywhere in the entire linked structure.
//	Your code should preferably run in O(n) time and use only O(1) memory.



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
#include<set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        int temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[temp] != nums[i]) {
                temp++;
                nums[temp] = nums[i];
            }
        }
        return temp + 1;
    }
};

int main()
{


    //ListNode head6(1); //only a variable
    vector<int>nums({ 1,1,2 });
    Solution question;
    question.removeDuplicates(nums);



    return 0;
}