
//factorial 5 = 5 * factorial(5-1)
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
	int factorial(int nums) {
		if (nums == 0) {
			return 1;
		}
		else 
			return nums * factorial(nums - 1);
	}
};


int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.factorial(5);


	return 0;
}
