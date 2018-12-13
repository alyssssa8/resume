
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
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};


int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.sortedArrayToBST(nums);
    Solution2 question2;
    question2.sortedArrayToBST(nums);

    return 0;
}