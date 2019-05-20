
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
    vector<int> sortedSquares(vector<int>& A) {
        for (auto& num : A) {
            num = num * num;
        }

        int left = 0;
        int right = A.size() - 1;

        vector<int> result(A.size(), 0);

        for (int i = result.size() - 1; i >= 0; --i) {
            if (A[left] > A[right]) {
                result[i] = A[left++];
            }
            else {
                result[i] = A[right--];
            }
        }
        return result;
    }
};



int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.sortedSquares(nums);
    /*Solution2 question2;
    question2.sortedSquares(nums);*/

    return 0;
}