
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
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            int temp = i;
            while (temp > 0) { // whe it is 0 , then stop
                if (temp % 10 == 0) {  //10 % 10 remainder is 0,  //Also, a self-dividing number is not allowed to contain the digit zero.
                    break;
                }
                if (i % (temp % 10) != 0) {
                    break;  // 13 %(13 % 10) 13 % 3 // when the number could not divid by itself, have reminder
                }
                temp = temp / 10; // 328 / 10 = 12; 32/10 = 1 ; 3/10 = 0 use this one to get the reminder
            }

            if (!temp) { // 1%1  reminder is 0, will be alway 0 if it could divide itself
                ans.push_back(i);
            };

        }
        return ans;

    }
};


int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.selfDividingNumbers(1,22);
    //Solution2 question2;
    //question2.sortedArrayToBST(nums);

    return 0;
}