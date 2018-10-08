

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
	int maxArea(vector<int>& height) {
		int water = 0;
		int i = 0, j = height.size() - 1;
		while (i < j) {
			int h = min(height[i], height[j]);
			water = max(water, (j - i) * h);
			while (height[i] <= h && i < j) i++;
			while (height[j] <= h && i < j) j--;
		}
		return water;
	}
};


class Solution {
public:
	int maxArea(vector<int> & height) {
		int start = 0, end = height.size() - 1;
		int result = 0;
		while (start < end) {
			if (height[start] > height[end]) {
				result = max(result, height[end] * (end - start));
				end--;
			}
			else if (height[start] < height[end]) {
				result = max(result, height[start] * (end - start));
				start++;
			}
			else {
				result = max(result, height[start] * (end - start));
				start++;
				end--;
			}
		}
		return result;
	}
};


class Solution {
public:
	int maxArea(vector<int>& height) {

		int myMax = 0;
		for (int i = 0; i < height.size(); i++) {
			for (int j = i + 1; j < height.size(); j++) {
				myMax = max(myMax, min(height[i], height[j]) * (j - i));
			}
		}

		return myMax;
	}
};

int main()
{

	vector<int>height({ 1,8,6,2,5,4,8,3,7 });
	Solution question;
	question.maxArea(height);
	
	return 0;
}
