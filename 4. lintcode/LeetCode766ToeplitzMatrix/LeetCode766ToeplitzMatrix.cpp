//https://leetcode.com/problems/toeplitz-matrix/description/
//A matrix is Toeplitz if every diagonal from top - left to bottom - right has the same element.
//
//Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
//
//
//Example 1:
//
//Input:
//matrix = [
//	[1, 2, 3, 4],
//		[5, 1, 2, 3],
//		[9, 5, 1, 2]
//]
//Output : True
//	Explanation :
//In the above grid, the diagonals are :
//"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
//In each diagonal all elements are the same, so the answer is True.
//Example 2 :
//
//	Input :
//	matrix = [
//		[1, 2],
//			[2, 2]
//	]
//	Output : False
//		Explanation :
//	The diagonal "[1, 2]" has different elements.
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


class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		vector<int>sample = matrix[0];
		int startPos = 1;
		int row = matrix.size();
		int col = matrix[0].size();
		while (startPos < row) {
			for (int i = 0; i < col - 1; i++) {
				if (matrix[startPos][i + 1] != sample[i]) {
					return false;
				}
			}
			sample = matrix[startPos];
			startPos++;
		}
		return true;

	}
};
 //53.73%
class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		for (int i = 0; i < matrix.size() - 1; i++) {
			for (int j = 0; j < matrix[0].size() - 1; j++) {
				if (matrix[i][j] != matrix[i + 1][j + 1]) {
					return false;
				}
			}
		}
		return true;
	}
};


class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		vector<int>sample = matrix[0];
		int col = matrix[0].size();
		int row = matrix.size();
		int i = 1;
		while (i<row) {
			for (int j = 0; j<col - 1; j++) {
				if (matrix[i][j + 1] != sample[j]) { 
					return 0;
				}
			}
			sample = matrix[i];
			i++;
		}
		return 1;
	}
};

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		for (int i = 1; i < matrix.size(); i++) {
			for (int j = 1; j < matrix[0].size(); j++) {
				if (matrix[i][j] != matrix[i - 1][j - 1]) {
					return false;
				}
			}
		}
		return true;
	}
};
int main()
{

	vector<vector<int>>nums({ { 1,2,3,4 },
		{ 5,1,2,3 },
		{ 9,5,1,2 } });
	Solution question;
	question.isToeplitzMatrix(nums);
	Solution question2;
	question2.isToeplitzMatrix(nums);

	return 0;
}
