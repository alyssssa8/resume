

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
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return true;

        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i + 1][0] < intervals[i][1]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>>nums({ { 15,16 }, {10,15 },{16,25} });
    Solution question;
    question.canAttendMeetings(nums);

    return 0;
}
