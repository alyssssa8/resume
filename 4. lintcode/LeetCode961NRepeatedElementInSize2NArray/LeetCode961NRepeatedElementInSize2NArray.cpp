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
#include<unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {      
            for (int i = 2; i < A.size(); ++i)
                if (A[i] == A[i - 1] || A[i] == A[i - 2])
                    return A[i];
            return A[0];       
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int>ans;
        for (int i : A) {
            ans[i]++;
            if (ans[i] == 2) {
                return i;
            }
        }
        return -1;
    }
};


int main()
{

    vector<string>nums({ "lll","hhh" });
    Solution question;
    vector<int> A({ 1, 2, 3, 3 });
    question.repeatedNTimes(A);
    //Solution2 question2;
    //question2.numUniqueEmails(nums);

    return 0;
}
