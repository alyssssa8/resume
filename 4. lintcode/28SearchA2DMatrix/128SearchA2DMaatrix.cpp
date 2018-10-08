//Write an efficient algorithm that searches for a value in an m x n matrix.
//
//This matrix has the following properties :
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//Example
//Consider the following matrix :
//
//[
//    [1, 3, 5, 7],
//    [10, 11, 16, 20],
//    [23, 30, 34, 50]
//]
//Given target = 3, return true.

//http://www.lintcode.com/en/problem/search-a-2d-matrix/
//https://www.jiuzhang.com/solution/search-a-2d-matrix/o
//https://leetcode.com/problems/search-a-2d-matrix/description/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return false;
		}
		int row = matrix.size();
		int col = matrix[0].size();
		int start = 0;
		int end = row * col - 1;
		while (start <= end) {
			int mid = start + (end - start) / 2;

			if (matrix[mid / col][mid % col] == target) {
				return true;
			}
			else if (matrix[mid / col][mid % col] > target) {
				end = mid - 1;

			}
			else {
				start = mid + 1;

			}
		}
		return false;
	}
};



class Solution2 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		if (matrix.size() == 0 || matrix[0].size() == 0) // need to check if the matrix is empty. // not use empty. 
		{
			return false;
		}
		int start = 0;
		int row = matrix.size();
		int col = matrix[0].size();
		int end = row * col - 1;


		while (start <= end)
		{
			int mid = start + (end - start) / 2;

			if (matrix[mid / col][mid % col] == target)  // / and % col  // here is == not =
			{
				return true;
			}
			else if (matrix[mid / col][mid % col] > target)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		return false;
	}
};
int main()
{
	int target = 90;
	vector<vector<int>> matrix({{ 1, 1 }
});
    vector<int>::iterator it;
   
	Solution question;
	question.searchMatrix(matrix, target);
    searchMatrix(matrix, target);
    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    // treat the matrix as an array, just taking care of indices
    // [0..n*m]
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]
    if (matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int row = matrix.size();
    int coloum = matrix[0].size();
    int start = 0;
    int end = row*coloum - 1;
    
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int currentValue = matrix[mid / coloum][mid%coloum];
        if (target < currentValue)
        {
            end = mid - 1;
        }
        else if (target > currentValue)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }

    return false;
}
