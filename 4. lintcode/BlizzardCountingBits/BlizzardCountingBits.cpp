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
    vector<int> getOneBits(int n) {
        std::vector<int> result;
        int counter = 0;
        bool flag = false;
        int temp;
        for (int i = 31; i >= 0; i--) {
            int mask = 1 << i;
            if ((n & mask) != 0) {
                if (flag == false) {
                    flag = true;
                    temp = i;              
                }
                counter++;
                result.push_back( temp - i + 1);
            }
        }
        result.insert(result.begin(), counter);
        return result;
    }


};


class Solution2 {
public:
    vector<int> getOneBits(int n) {
        std::vector<int> result;
        int counter = 0;
        int first_bit = 0;
        for (int i = 31; i >= 0; i--) {
            int mask = 1 << i;  // position  000000-111111         256
            if ((n & mask) != 0) { //what is n
                first_bit = i;  // output
                break;
            }
        }

        for (int i = first_bit; i >= 0; i--) {
            int mask = 1 << i;
            if ((n & mask) != 0) {
                counter++;
                result.push_back(first_bit - i + 1);
            }
        }
        result.insert(result.begin(), counter);
        return result;
    }
};

int main()
{

    Solution question;
    question.getOneBits(161);
    return 0;
}
