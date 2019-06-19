//https://leetcode.com/problems/count-primes/description/
//https://www.youtube.com/watch?v=Kwo2jkHOyPY
//http://zxi.mytechroad.com/blog/math/leetcode-204-count-primes/

//Count the number of prime numbers less than a non - negative number, n.
//
//Example :
//
//	Input : 10
//	Output : 4
//	Explanation : There are 4 prime numbers less than 10, they are 2, 3, 5, 7.


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
#include<numeric>
using namespace std;



// Author: Huahua
//prefer this solution. 
class Solution3 {
public:
	int countPrimes(int n) {
		if (n < 3) return 0;

		vector<unsigned char> f(n, 1);
		f[0] = f[1] = 0;
		for (int i = 2; i <= sqrt(n); ++i) {
			if (!f[i]) continue;
			for (int j = i; j <= n / i; j++) // before i * i already changed the value. 
				f[j * i] = 0;
		}
		/*
		for (int i = 2; i <= sqrt(n); ++i) {
			if (f[i] == 1){  //if (f[i] != 0){ 
                for (int j = i; j <= n / i; j++) // before i * i already changed the value. 
                    f[j * i] = 0;
            }
		}	
		
		*/
		int ans = accumulate(f.begin(), f.end(), 0);
		return ans;
	}
};

// Author: Huahua
//use this one!
class Solution2 {
public:
	int countPrimes(int n) {
		if (n < 3) return 0;
		vector<int> f(n, 1);
		f[0] = f[1] = 0;
		for (int i = 2; i <= sqrt(n); ++i) {  // 1 2 3 4 5 6 7 8 9 10 | if n = 10, i will stop at 3. 3*3 = 9
			// if 4*4=16.  before 3*3, all deleted. 3*4 already if still less than 
			if (!f[i]) continue;
            for (int j = i * i; j < n; j += i) {
                f[j] = 0;
            }
		}
		int ans = accumulate(f.begin(), f.end(), 0);
		return ans;
	}
};

class Solution {
public:
	int countPrimes(int n) {
		vector<int>myVector(n, 1);
		myVector[0] = myVector[1] = 0;

		int i = 2;
		while (i * i  < n) {
			if (myVector[i] == 1) {
				int j = i;
				while (j < n) {
					j *= i;
					myVector[j * i] = 0;
					j++;
				}
			}
			i++;
		}
		int ans = accumulate(myVector.begin(), myVector.end(), 0);
		return ans;
	}
};

int main()
{
	int num2 = 10;
	vector<int>nums({ 3, 1 ,0 });
	Solution question;
	question.countPrimes(num2);
	Solution question2;
	question2.countPrimes(num2);

	return 0;
}