

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
    int findComplement(int num) {
        int revert = ~0;
        while (revert & num) revert <<= 1;
        return revert ^ (~num);
    }
};

class Solution {
public:
    int findComplement(int num) {
        int copy = num;
        int i = 0;

        while (copy != 0) {
            copy >>= 1;
            num ^= (1 << i);
            i += 1;
        }
        return num;
    }
};


int main()
{

    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.findComplement(13);
    Solution2 question2;
    question2.findComplement(8);

    return 0;
}