
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
class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] = A[i] * A[i];
        }
        vector<int>ans(A.size(), 0);
        int left = 0;
        int right = A.size() - 1;
        for (int i = A.size() - 1; i < A.size(); i--) {
            if (A[left] > A[right]) {
                ans[i] = A[left];
                left++;
            }
            else {
                ans[i] = A[right];
                right--;
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i <A.size(); i++){
            A[i] = A[i] * A[i];
        }       
        vector<int>ans(A.size(), 0);
        int left = 0;
        int right =A.size() - 1;
        for (int i = A.size() - 1; i < A.size(); i--){
            if(A[left] > A[right]){
                ans[i] = A[left];
                left++;
            }
            else {
                 ans[i] = A[right];
                 right--;
            }
        }
        
        return ans;
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