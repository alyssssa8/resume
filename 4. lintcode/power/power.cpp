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
	int Power(int base, int exponent)
	{
		if (exponent == 1)
			return base;
		else
			return base * Power(base, exponent - 1);
	}

};


int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.Power(5);


	return 0;
}
