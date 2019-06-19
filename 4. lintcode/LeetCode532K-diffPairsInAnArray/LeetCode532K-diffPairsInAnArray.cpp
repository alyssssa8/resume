//
//https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
//
//Given an array of integers and an integer k, you need to find the number of unique k - diff pairs in the array.Here a k - diff pair is defined as an integer pair(i, j), where i and j are both numbers in the array and their absolute difference is k.
//
//Example 1 :
//	Input : [3, 1, 4, 1, 5], k = 2
//	Output : 2
//	Explanation : There are two 2 - diff pairs in the array, (1, 3) and (3, 5).
//	Although we have two 1s in the input, we should only return the number of unique pairs.
//	Example 2 :
//	Input : [1, 2, 3, 4, 5], k = 1
//	Output : 4
//	Explanation : There are four 1 - diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
//	Example 3 :
//	Input : [1, 3, 1, 5, 4], k = 0
//	Output : 1
//	Explanation : There is one 0 - diff pair in the array, (1, 1).
//	Note :
//	The pairs(i, j) and (j, i) count as the same pair.
//	The length of the array won't exceed 10,000.
//	All the integers in the given input belong to the range : [-1e7, 1e7].
//
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
#include<unordered_set>
using namespace std;
// 3, 1, 4, 1, 5 
//2

//1,1,1,1,1 | k = 0
//
class Solution3 {
public:
	int findPairs(vector<int>& nums, int k) {

		if (k < 0) {
			return 0;
		}
		unordered_set<int> starters; // for the repeatation.
		unordered_map<int, int> indices;
		for (int i = 0; i < nums.size(); i++) {
			if (indices.find(nums[i] - k) != indices.end()) { //Searches the container for elements with a key equivalent to k and returns the number of matches.
				starters.insert(nums[i] - k);
			}
			if (indices.find(nums[i] + k) != indices.end()) {
				starters.insert(nums[i]);
			}

			indices[nums[i]] += 1;
		}

		return starters.size();

	}
};
//push the value to the map, the find all the value whih is match p.first + k
// not repeat value count: (3,1) count as one pair. 
//Input: [3, 1, 4, 1, 5], k = 2
//	Output : 2
class Solution2 {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0;  // must have this
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]]++;
		}
		int cnt = 0;
		for (auto p : m) {
			//m[3].first;
			//Searches the container for elements with a key equivalent to k and returns the number of matches.
			if ((k != 0 && m.count(p.first + k) != 0)) { 
				// count return the number of the value
				// return the position of the value. 

				++cnt;
			}
			if ((k == 0 && p.second > 1)) { // deal with k = 0. when the value more then 1, which means the count of that value more then 1. 
				++cnt;
			}

			//if ((!k && p.second > 1) || (k && m.count(p.first + k))) ++cnt;
		}
		return cnt;
	}
};

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0;  // must have this
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]]++;
		}
		int cnt = 0;
		for (auto p : m) {
			//m[3].first;
			//Searches the container for elements with a key equivalent to k and returns the number of matches.
			if ((k != 0 && m.find(p.first + k) != m.end())) {
				++cnt;
			}
			if ((k == 0 && p.second > 1)) { // deal with k = 0. when the value more then 1, which means the count of that value more then 1. 
				++cnt;
			}

			//if ((!k && p.second > 1) || (k && m.count(p.first + k))) ++cnt;
		}
		return cnt;
	}
};
// use this one
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.empty() || k < 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int p1 = 0;            // points to first member of the pair
        int p2 = p1 + 1;       // points to second member of the pair
        int result = 0;
        while (p1 < nums.size() && p2 < nums.size()) {
            if (p1 == p2) {
                p2++;
                continue;
            }
            if (p1 > 0 && nums[p1] == nums[p1 - 1]) {
                // to avoid dupes
                p1++;
                continue;
            }
            int diff = abs(nums[p1] - nums[p2]);

            if (diff == k) {
                result++;
                p1++;
                p2++;
            }
            else if (diff < k) {
                p2++;
            }
            else {
                p1++;
            }
        }

        return result;
    }

};


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

int main()
{

	vector<int>nums({ 3, 1, 4, 1, 5 });
	Solution question;
	question.findPairs(nums,2);
	Solution2 question2;
	question2.findPairs(nums,2);

	return 0;
}