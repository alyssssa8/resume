//https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
//
//Let's call an array A a mountain if the following properties hold:
//
//A.length >= 3
//There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1]
//	Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1].


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
	int peakIndexInMountainArray(vector<int>& A) {

		int start = 0, end = A.size() - 1;

		while (start < end) {
			int mid = start + (end - start) / 2;
			if (A[mid] < A[mid + 1]) {
				start = mid + 1;
			}
			else {
				end = mid;
			}
		}
		return end;
	}
};
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for (int i = 1; i < A.size(); i++) {
            if (A[i] < A[i - 1]) {
                return i - 1;
            }
        }
        return 0;
    }
};

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		/*if (heaters.size() == 0) {
		return 0;
		}*/
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int radius = 0;
		int index = 0;
		for (int i = 0; i < houses.size(); i++) {
			while (index + 1 < heaters.size() && (abs(heaters[index + 1] - houses[i]) <= abs(heaters[index] - houses[i]))) {
				index++;
			}
			radius = max(radius, abs(heaters[index] - houses[i]));
		}
		return radius;
	}
};
int main()
{
	vector<int>houses{ 1,2,3,4 };

	vector<int>heaters{};


	Solution question;
	question.findRadius(houses, heaters);

	return 0;
}