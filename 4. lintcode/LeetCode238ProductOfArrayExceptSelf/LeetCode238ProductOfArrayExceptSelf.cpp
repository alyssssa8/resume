
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

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1;
        int count = 0;
        bool flag = false;
        int index;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                sum *= nums[i];
            }
            else {
                count++;
                if (count >= 2) {
                    for (int i = 0; i < nums.size(); i++) {
                        nums[i] = 0;
                    }
                    return nums;
                }
                flag = true;
                index = i;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (flag == true) {
                    for (int j = 0; j < nums.size(); j++) {
                        nums[i] = 0;
                    }
                    nums[index] = sum;
                }

                else {
                    nums[i] = sum / nums[i];
                }
            }

        }
        return nums;

    }
};

class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N, 1);

        for (int i = 1; i < N; i++) {

            res[i] = res[i - 1] * nums[i - 1];
        }

        int r_prod = 1;
        for (int i = N - 1; i >= 0; i--) {
            res[i] *= r_prod;
            r_prod *= nums[i];
        }

        return res;
    }
};
int main()
{

    vector<int>nums({ 1, 2 ,3,4 });
    Solution question;
    question.productExceptSelf(nums);
    Solution2 question2;
    question2.productExceptSelf(nums);

    return 0;
}