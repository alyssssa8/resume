//https://leetcode.com/problems/climbing-stairs/description/
//You are climbing a stair case.It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
//
//Note : Given n will be a positive integer.
//
//	Example 1 :
//
//	Input : 2
//	Output : 2
//	Explanation : There are two ways to climb to the top.
//	1. 1 step + 1 step
//	2. 2 steps
//	Example 2 :
//
//	Input : 3
//	Output : 3
//	Explanation : There are three ways to climb to the top.
//	1. 1 step + 1 step + 1 step
//	2. 1 step + 2 steps
//	3. 2 steps + 1 step
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


//use this
class Solution3 {
public:
	int climbStairs(int n) {
		int two = 1;
		int one = 1;
		int curr = 1;
		for (int i = 2; i <= n; i++) {
			curr = two + one;
			two = one;
			one = curr;
		}
		return curr;
	}
};



class Solution5 {
public:
    int climbStairs(int n) {

        vector<int>memo(n + 1, 0);
        return climb_Stairs(0, n, memo);
    }
    int climb_Stairs(int i, int n, vector<int>& memo) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (memo[i] > 0) {
            return memo[i];
        }
        memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
        return memo[i];
    }

};

class Solution4 {
public:
    int climbStairs(int n)
    { // may not need +1, could be steps(n,0)
        vector<int> steps(n +1, 0);  //if n ==3, steps should be steps[  0,1,2 ] 
        steps[0] = 1;
        steps[1] = 2;
        for (int i = 2; i < n; i++)
        {
            steps[i] = steps[i - 2] + steps[i - 1];
        }
        return steps[n - 1];
    }
};

class Solution {
private:
	vector<int>f;
public:
	int climbStairs(int n) {
		f = vector<int>(n + 1, 0); //need one more size
		return numOfSolutions(n);

	}

	int numOfSolutions(int n) {
		if (n <= 1) {
			return 1;
		};

        //same as above!
       /* if (n == 1) {
            return 1;
        };
        if (n == 2) {
            return 2;
        }
*/

		if (f[n]>0) {		
			return f[n]; //pay attention on this one, when there already have value, they just use the value. 
            //because recursive, 
		}
		f[n] = numOfSolutions(n - 1) + numOfSolutions(n - 2);
		return f[n];
	}
};

int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution4 question;
	int ans = question.climbStairs(9);
	/*Solution question2;
	question2.climbStairs(8);*/

	return 0;
}
