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
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> store(nums.size(), 1);
        if (nums.size() == 0) {
            return 0;
        }
        int ans = 1;
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    store[i] = max(store[j] + 1, store[i]);
                    ans = max(ans, store[i]);
                }
            }
        return ans;
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ladder(1);
        if (nums.empty()) return 0;
        ladder[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int m = int(ladder.size());
           // bool foundless = false;
            for (int j = m - 1; j >= 0; --j) {
                if (nums[i] > ladder[j]) {
                    if (j + 1 == ladder.size()) {
                        ladder.push_back(nums[i]);
                    }
                    else {
                        ladder[j + 1] = min(ladder[j + 1], nums[i]);
                    }
                    //foundless = true;
                    break;
                }
            }
            //if (!foundless) ladder[0] = min(ladder[0], nums[i]);
            ladder[0] = min(ladder[0], nums[i]);
        }
        return ladder.size();
    }
};


class Solution3 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return nums.size();

        vector<int>::iterator m = nums.begin();  // m will mark the virtual "S.end()".
        for (int& val : nums) {
            auto it = lower_bound(nums.begin(), m, val);
kjm            *it = val;
            if (it == m)
                m++;
        }

        return m - nums.begin();
    }
};
int main()
{

    vector<int>nums({ 5,6,7,1,2,8,3,4,0,5,9 });  // 10 5 7 101
    Solution question;
    question.lengthOfLIS(nums);
    Solution2 question2;
    question2.lengthOfLIS(nums);
    Solution3 question3;
    question3.lengthOfLIS(nums);
    return 0;
}
