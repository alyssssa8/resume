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




// Author: Huahua
// Runtime: 6 ms (better than 98.66%)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>myVector(nums.size());
        myVector[0] = nums[0];
        int ans = myVector[0];

        for (int i = 1; i < nums.size(); i++)
        {
            myVector[i] = max(nums[i] + myVector[i - 1], nums[i]);
            ans = max(ans, myVector[i]);

        }

        return ans;
    }
};

int main()
{

    vector<int>nums({ -1, -2});
    Solution question;
    question.maxSubArray(nums);
    Solution question2;
    question2.maxSubArray(nums);

    return 0;
}