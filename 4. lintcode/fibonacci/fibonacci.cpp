//0,1,1,2,3,5,8,13,21,34,55,89,144
//				1
//			1	 2	  1
//		1     3     3      1
//	1      4	 6		4		1	

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
	int Fibonacci(int n)
	{
		if (n <= 2)
			return n;
		else
			return Fibonacci(n - 1) + Fibonacci(n - 2);
	}

};


int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.Fibonacci(5);


	return 0;
}
