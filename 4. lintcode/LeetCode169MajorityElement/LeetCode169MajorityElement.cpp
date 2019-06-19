
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
    int majorityElement(vector<int> &num) {
        int majorityIndex = 0;
        for (int count = 1, i = 1; i < num.size(); i++) {
            num[majorityIndex] == num[i] ? count++ : count--;
            if (count == 0) {
                majorityIndex = i;
                count = 1;
            }
        }

        return num[majorityIndex];
    }
};

int main()
{
    vector<int> nums( { 3,2,3 });
    Solution question;
    question.majorityElement(nums);
    return 0;
}
