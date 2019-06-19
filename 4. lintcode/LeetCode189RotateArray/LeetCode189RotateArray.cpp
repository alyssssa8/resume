
#include <iostream>
#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include <vector>
using namespace std;

class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int temp = 0;
        for (; k = k % n; n -= k)
        {
            for (int i = 0; i < k; i++)
            {
                swap(nums[i + temp], nums[n - k + i + temp]);
            }
            temp += k;
        }
    }
};
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if ((n == 0) || (k <= 0))
        {
            return;
        }

        // Make a copy of nums
        vector<int> numsCopy(n);
        for (int i = 0; i < n; i++)
        {
            numsCopy[i] = nums[i];
        }

        // Rotate the elements.
        for (int i = 0; i < n; i++)
        {
            nums[(i + k) % n] = numsCopy[i];
        }
    }
};

//own, does not work
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if ((n == 0) || (k <= 0))
        {
            return;
        }

        vector<int> temp(k);
        int i = nums.size() - 1;
        for (int count = 0; count < k; count++) {
            temp[count] = nums[i];
            i--;
        }
        int newCount = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i < k) {
                nums[i] = temp[newCount];
                newCount++;
            }
            else {
                nums[i] = nums[i - k];
            }
        }
        return;
    }
};

int main()
{
    vector<int> num({ 1,2,3,4,5,6,7 });
   /* Solution question;
    question.rotate(num,3);*/
    Solution3 question3;
    int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
    question3.rotate(nums,7,3);
    return 0;

}

