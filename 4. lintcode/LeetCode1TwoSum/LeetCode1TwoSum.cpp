


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
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> myMap;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {

            if (myMap.find(target - nums[i]) != myMap.end()) {
                ans.push_back(myMap[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            myMap[nums[i]] = i;
        }
        return ans;
    }
};
int main()
{
    //vector<int>numbers{ 0,1,2,3,4,5,6,7,8,9};
    //vector<int>numbers{ 2,7,11,14,15 };
    vector<int>numbers{ 2,3,6,10,11,12,13 };

    int target = 8;


    /*Solution question;
    question.twoSum(numbers, target);*/
    Test question2;
    vector<int> result;
    result = question2.twoSum(numbers, target);
    Test2 question3;
    question3.twoSum(numbers, target);
    vector<int>::iterator iter;
    for (iter = result.begin(); iter != result.end(); iter++)
    {
        cout << *iter << "  ";
    }
    cout << endl;

    return 0;
}