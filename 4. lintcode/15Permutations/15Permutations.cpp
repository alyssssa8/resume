//https://leetcode.com/problems/permutations/description/
//https://www.jiuzhang.com/solution/permutations
//
//http://www.lintcode.com/problem/permutations/
//
//Given a collection of distinct integers, return all possible permutations.
//
//Example :
//
//	Input : [1, 2, 3]
//	Output :
//	[
//		[1, 2, 3],
//		[1, 3, 2],
//		[2, 1, 3],
//		[2, 3, 1],
//		[3, 1, 2],
//		[3, 2, 1]
//	]



#include <iostream>

#include <math.h>
#include <algorithm>
#include<vector>
#include<string>
#include <queue>
#include <stack>
#include <list>
#include <map>   //hash table
#include <vector>
#include<unordered_set>
#include<array>
#include<set>
using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums);
//void helper(vector<vector<int> > &results, vector<int> &permutation, vector<int> &nums, bool used[]);
//void permuteRecursive(vector<int> &num, int k);
vector<vector<int> > permute(vector<int> &num);

vector<vector <int> > P;
int len;
class Solution5 {
private:
	vector<vector<int>>ans;
	vector<int>tempAns;

public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(nums);
		return ans;
	}

	void dfs(vector<int> & nums) {
		if (tempAns.size() == nums.size()) {
			ans.push_back(tempAns);
			return;
		}
		for (int i = 0; i <nums.size(); i++) {
			if (find(tempAns.begin(), tempAns.end(), nums[i]) == tempAns.end()) {
				tempAns.push_back(nums[i]);
				dfs(nums);
				tempAns.pop_back();
			}
		}
	}
};

class Solution4 {
private:

	vector<vector<int>> ans;
	vector<int> tempAns;

public:
	vector<vector<int>> permute(vector<int>& nums) {
		bool *used = new bool[nums.size()];

		for (int i = 0; i < nums.size(); i++)
		{
			used[i] = false;
		}

		sort(nums.begin(), nums.end());
		dfs(nums, used);
		delete[] used;
		return ans;

	}
	void dfs(vector<int>& nums, bool used[])
	{

		if (tempAns.size() == nums.size())
		{
			ans.push_back(tempAns);
			return;
		}


		for (int i = 0; i <nums.size(); i++)
		{
			if (used[i] == true)
			{
				continue;
			}
			used[i] = true;
			tempAns.push_back(nums[i]);
			dfs(nums, used);
			tempAns.pop_back();
			used[i] = false;

		}
	}
};

class Solution_1 {

public:

	void permuteRecursive(vector<int> &num, int k) {

		if (k == len) {
			 //one permutation instance
			vector<int>::iterator iter;
			for (iter = num.begin(); iter != num.end(); iter++) {

				cout << *iter << ",";
			}
			P.push_back(num);
			return;
		}

		for (int i = k; i < len; i++) {
			cout << "first:  " << "k: " << k << "   i:" << i << endl;
			swap(num[k], num[i]);           //  swap two positions
			permuteRecursive(num, k + 1);
			cout << "second:  " << "k: " << k << "   i:" << i << endl;
			swap(num[k], num[i]);           //  swap back to reset
		}
	}

	vector<vector<int> > permute(vector<int> &num) {

		len = num.size();
		permuteRecursive(num, 0);

		return P;
	}

};



//
//func(layer n) {
//
//	for each available value {
//
//		// add a value to current layer
//	
//
//		// verify next layer call func(layer n + 1)
//
//
//		// remove the value from current layer
//	}
//}
//
//
//
//select_n_numbers(int n) {
//
//	// pick one number
//
//	// call select_n_numbers(n - 1)
//}
//
//
//sum_n_numbers(int n) {
//	// sum = current + sum_n_numbers(n - 1)
//}





class Solution3 {
	unordered_set<int> V;
	vector<int> path;
	vector<vector<int>> ans;

	void go_layer3(const vector<int>& A) {
		int M = (int)path.size(),
			N = (int)A.size();
		if (M == N)
		{
			ans.push_back(path);
			return;
		}

	}

	void go_layer2(const vector<int>& A) {
		int M = (int)path.size(),
			N = (int)A.size();

		 //V = [0]
		for (int i = 0; i<N; ++i)
		{
			if (V.insert(i).second == true) {
				path.push_back(A[i]);  // V = [ 0, 2 ]
				go_layer3(A); // 
				V.erase(i); // V = [ 0,1 ]  A =[1,2]
				path.pop_back();
			}
			else {

			}
		}
	}

	void go_layer1(const vector<int>& A) {
		int M = (int)path.size(),
			N = (int)A.size();

		 //V = [0]
		for (int i = 0; i<N; ++i)
		{
			if (V.insert(i).second == true) {
				path.push_back(A[i]);  // V = [ 0, 2 ]
				go_layer2(A); // 
				V.erase(i); // V = [ 0,1 ]  A =[1,2]
				path.pop_back();
			}
			else {

			}
		}
	}

	void go_layer0(const vector<int>& A) {
		int M = (int)path.size(), 
			N = (int)A.size();
		if (M == N) 
		{
			ans.push_back(path);
			return;
		}
		// V = [0]
		for (int i = 0; i<N; ++i) 
		{
			if (V.insert(i).second == true) {
				path.push_back(A[i]);  // V = [ 0, 2 ]
				go_layer0(A); // 
				V.erase(i); // V = [ 0,1 ]  A =[1,2]
				path.pop_back();
			}
			else {

			}
		}
	}
public:
	vector<vector<int>> permute(vector<int> &A) {
		ans.clear();
		go_layer0(A);
		return ans;
	}
};

class Solution {
	unordered_set<int> V;
	vector<int> path;
	vector<vector<int>> ans;


	void go(const vector<int>& A) {
		int M = (int)path.size(), N = (int)A.size();
		if (M == N) {
			ans.push_back(path);
			cout << endl;
			cout << "---------------------" << endl;
			return;
		}
		// V = [0]
		for (int i = 0; i<N; ++i) {
			if (V.insert(i).second == true) { //if insert success, return true. 
				cout << A[i] << " , ";
				path.push_back(A[i]);  // V = [ 0, 2 ]
				go(A); // 
				V.erase(i); // V = [ 0 ]
				path.pop_back();
			}
			else {

			}
		}
	}

public:
	vector<vector<int>> permute(vector<int>& A) {
		ans.clear();
		go(A);
		return ans;
	}
};


int main()
{


	/*
	vector<int> candidates({ 1,2,3 });
	vector<vector<int>> result = permute(candidates);
	vector< vector<int> >::iterator row;
	vector<int>::iterator col;
	cout << "return result: " << endl;
	for (row = result.begin(); row != result.end(); row++) {
	for (col = row->begin(); col != row->end(); col++) {
	cout << *col;
	}
	cout << endl;
	}

	return 0;
	*/

	vector<int> candidates({ 1,2,3 });
	Solution test;
	test.permute(candidates);
	return 0;
}
