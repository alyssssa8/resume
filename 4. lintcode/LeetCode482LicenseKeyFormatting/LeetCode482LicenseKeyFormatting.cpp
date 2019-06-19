

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
    string licenseKeyFormatting(string S, int K) {

        int inputDashes = 0;
        for (char c : S) {
            if (c == '-') {
                inputDashes++;
            }
        }

        // number of groups of K characters + 1 if there's another group smaller than K
        int outputDashes = (S.length() - inputDashes + K - 1) / K - 1;

        // create result string of correct length
        int totalLength = S.length() - inputDashes + outputDashes;
        string result;
        if (totalLength > 0) {
            result = string(totalLength, '-');
        }


        // fill-in the result string
        int i = 1; int j = 1;
        while (i <= totalLength && j <= S.length())
        {
            if (i % (K + 1) == 0)
            {
                i++;
                continue;
            }

            while (j <= S.length() && S[S.length() - j] == '-') {
                j++;
            }
            result[result.length() - i] = toupper(S[S.length() - j]);
            i++;
            j++;
        }
        return result;
    }
};


int main()
{

    
    vector<int>nums1({ 0 });
    vector<int>nums2({ 1 });
    Solution question;
    question.licenseKeyFormatting("2-4AOr7-4k", 4);
    /*   Solution question2;
       question2.merge(250);*/
    return 0;
}