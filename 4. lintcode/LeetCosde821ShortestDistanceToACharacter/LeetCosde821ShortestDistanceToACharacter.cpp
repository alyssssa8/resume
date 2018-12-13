

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
    vector<int> shortestToChar(string S, char C) {
        vector<int>p(S.size(), S.size() + 1);
        vector<int>pos;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                pos.push_back(i);
            }
        }
        for (int k = 0; k < pos.size(); k++) {
            for (int j = 0; j < S.size(); j++) {
                p[j] = min(p[j], abs(pos[k] - j));
            }
        }

        return p;
    }
};
// ayusofayush
class Solution2 {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> res(n, n);
        int pos = -n;
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) pos = i;
            res[i] = min(res[i], abs(i - pos));
        }
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C)  pos = i;
            res[i] = min(res[i], abs(i - pos));
        }
        return res;
    }
};


class Solution3 {
public:
    std::vector<int> shortestToChar(std::string S, char C) {
        std::vector<int> result;
        result.reserve(S.size());

        auto first = S.find(C);
        if (first == std::string::npos) return result;
        for (int i = 0; i <= first; ++i) result.push_back(first - i);

        for (auto last = S.find(C, first + 1); last != std::string::npos; first = last, last = S.find(C, first + 1)) {
            auto mid = first + (last - first) / 2;
            for (auto i = first + 1; i <= mid; ++i) result.push_back(i - first);
            for (auto i = mid + 1; i <= last; ++i) result.push_back(last - i);
        }

        for (auto i = first + 1; i < S.size(); ++i) result.push_back(i - first);

        return result;
    }
};





int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.shortestToChar("dfdf",'c');
    Solution2 question2;
    question2.shortestToChar("dfdf", 'c');

    return 0;
}