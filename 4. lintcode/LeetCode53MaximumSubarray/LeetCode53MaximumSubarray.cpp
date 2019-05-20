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

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            ans = max(ans, sum);
            sum = max(sum, 0);
              
        }
        return ans;
    }
};
int main()
{

    vector<int>nums({ -2,1,-3,4,-1,2,1,-5,4});
    Solution question;
    cout << question.maxSubArray(nums) << endl;;
    Solution2 question2;
    cout << question2.maxSubArray(nums) << endl;;

    return 0;
}