

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
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + carry > 9) {
                carry = 1;
                digits[i] = (digits[i] + carry) % 10;
            }
            else {
                digits[i] += carry;
                carry = 0;
                break;
            }
        }

        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
int main()
{

    string nums1 = "ab";
    string nums2 = "aa";
    vector<int> digits({ 1,2,3 });
    Solution question;
    question.plusOne(digits);
    return 0;
}
