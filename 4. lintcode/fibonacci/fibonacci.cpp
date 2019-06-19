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

//100%
class Solution3 {
public:
    int fib(int N) {
        vector<int> v;

        v.push_back(0);
        v.push_back(1);
        for (auto i = 2; i <= N; i++)
            v.push_back(v[i - 1] + v[i - 2]);

        return v[N];
    }
};
class Solution2 {
public:
	int Fibonacci(int n)
	{
		if (n <= 1)
			return n;
		else
			return Fibonacci(n - 1) + Fibonacci(n - 2);
	}

};

class Solution {
public:
    int fib(int N) {
        if (N < 2)
            return N;
        int a = 0, b = 1, c = 0;
        for (int i = 1; i < N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;

    }
};
int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.Fibonacci(5);


	return 0;
}
