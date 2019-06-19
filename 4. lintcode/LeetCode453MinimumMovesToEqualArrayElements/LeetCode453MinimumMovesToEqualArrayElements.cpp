
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
//[1,2,3]
//[1,1,1]
class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long total = 0;
        bool flag = true;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            if (i > 0 && nums[i - 1] != nums[i] ) {
                flag = false;
            }
        }
        int count = 0;
        // if (total%nums.size() ==0){
        //     return 0;
        // }
        if (flag == true) {
            return 0;
        }
        while ((total + nums.size() - 1) % nums.size() != 0) {
            count++;
            total += nums.size() - 1;
        }
        return count + 1;
    }
};
int main()
{
    vector<int> nums({ 1,1,1 });
    Solution question;
    question.minMoves(nums);
    return 0;
}
