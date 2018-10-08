//https://leetcode.com/problems/transpose-matrix/description/
//
//Given a matrix A, return the transpose of A.
//
//The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
//
//
//
//Example 1:
//
//Input: [[1, 2, 3], 
//        [4, 5, 6], 
//        [7, 8, 9]]
//	Output : [[1, 4, 7], 
//            [2, 5, 8], 
//            [3, 6, 9]]
//	Example 2 :
//
//	Input : [[1, 2, 3], 
//           [4, 5, 6]]
//	Output : [[1, 4], 
//            [2, 5], 
//            [3, 6]]
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

class Solution2 {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>> res(A[0].size(), vector<int>());
		if (A.size() == 0) {
			return res;
		}
		for (int r = 0; r<A.size(); ++r)
			for (int c = 0; c<A[0].size(); ++c)
				res[c].push_back(A[r][c]);
		return res;
	}
};

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>> ans(A[0].size(), vector<int>(A.size())); // this is not reorder the size of array, so could not use / or % to slove this problem. 
		if (A.size() == 0) {
			return ans;
		}
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[0].size(); j++) {
				ans[j][i] = A[i][j];
			}
		}
		return ans;
	}
};



int main()
{

	vector<vector<int>>nums({ { 1 },{ 4 }});
	//vector<vector<int>>nums({ { 1,2,3 },{ 4,5,6 },{ 7,8,9 } });
	Solution question;
	question.transpose(nums);
	Solution question2;
	question2.transpose(nums);

	return 0;
}