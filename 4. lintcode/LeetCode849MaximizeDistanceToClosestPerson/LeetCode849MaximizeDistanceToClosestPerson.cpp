//https://leetcode.com/problems/maximize-distance-to-closest-person/description/
//
//In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.
//
//There is at least one empty seat, and at least one person sitting.
//
//Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
//
//Return that maximum distance to closest person.
//
//Example 1:
//
//Input: [1, 0, 0, 0, 1, 0, 1]
//	Output : 2
//	Explanation :
//	If Alex sits in the second open seat(seats[2]), then the closest person has distance 2.
//	If Alex sits in any other open seat, the closest person has distance 1.
//	Thus, the maximum distance to the closest person is 2.
//	Example 2 :
//
//	Input : [1, 0, 0, 0]
//	Output : 3
//	Explanation :
//	If Alex sits in the last seat, the closest person is 3 seats away.
//	This is the maximum distance possible, so the answer is 3.
//	Note :
//
//	1 <= seats.length <= 20000
//	seats contains only 0s or 1s, at least one 0, and at least one 1.
//


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
	int maxDistToClosest(vector<int>& seats) {
		int space = 0;
		for (int i = 0; i < seats.size(); i++) {
			int cnt = 0;
			while (i + cnt < seats.size() && seats[i + cnt] == 0) {
				cnt++; // count the number of contiguous zeros
			}
			if (i == 0 || i + cnt == seats.size()) {
				space = max(space, cnt); //for [0,0,0,1] or [1,0,0,0], distance is cnt = 3
			}
			else {
				space = max(space, (cnt + 1) / 2); // for [1,0,0,0,1] or [1,0,0,0,0,1] distance is (cnt + 1) / 2 = 2
			}
			i += cnt;
		}
		return space;

	}
};
// 1000 or 0111


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0;
        int start = 0;
        for (int i = 0; i < seats.size(); i++) {
            start = i;
            while (seats[i] == 0 && i < seats.size()) {
                i++;
            }
            if (start == 0 || (i == seats.size() && seats[i - 1] == 0)) {
                ans = max(ans, i - start);
            }
            else {
                ans = max(ans, (i - start + 1) / 2);
            }
        }
        return ans;
    }
};
int main()
{

	vector<int>nums({1, 0,0,0 });
	Solution question;
	question.maxDistToClosest(nums);
	Solution question2;
	question2.maxDistToClosest(nums);

	return 0;
}