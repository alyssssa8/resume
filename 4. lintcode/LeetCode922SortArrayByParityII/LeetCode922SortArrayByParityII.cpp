
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
    vector<int> sortArrayByParityII(vector<int>& A) {

        for (int i = 0, j = 1; i < A.size(); i += 2, j += 2) {
            while (i < A.size() && A[i] % 2 == 0) {
                i += 2;
            }
            while (j < A.size() && A[j] % 2 != 0) {
                j += 2;
            }
            if (i < A.size()) {
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};

class Solution2 {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mx = A[0], mn = A[0];
        for (int a : A) {
            mx = max(mx, a), mn = min(mn, a);
        }
        return max(0, mx - mn - 2 * K);

    }
};

int main()
{

    vector<int>nums({ 0, 10,});
    Solution question;
    question.sortArrayByParityII(nums);
    Solution2 question2;
    question2.smallestRangeI(nums,2);

    return 0;
}