

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



//1*2*3*4*5 = 120
//factorial 5 = 5 * factorial(5-1) = 120
//factorial 4 = 4 * factorial(4-1) = 24
//factorial 3 = 3 * factorial(3-1) = 6
//factorial 2 = 2 * factorial(2-1) = 2
//factorial 1 = 5 * factorial(1-1) = 1
// factorial(0) = 1

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
