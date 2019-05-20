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
    string smallestString(long weight) {
        const int size = 26;
        const long limit = 1e16;
        std::vector<long> weights(size, 0);
        std::string result = "";
        int max_size = 0;
        weights[0] = 1;

        for (int i = 1; i < size; i++) {
            weights[i] = (i + 1) * weights[i - 1] + (i + 1);
            if (weights[i] > limit) {
                max_size = i - 1;
                break;
            }
        }
        int current_index = max_size;
        while (weight> 0) {
            if (weight >= weights[current_index]) {
                long div = weight / weights[current_index];
                char current_char = 'A' + current_index;
                for (int i = 0; i < div; i++) {
                    result = current_char + result;
                }
                weight = weight - div * weights[current_index];
            }
            current_index--;
        }
        return result;
    }
};


class Solution2 {
public:
    string Test(long int weight) {
        const int size = 26;
        const long int limit = 1e16;
        std::vector<long int> weights(size, 0);
        std::string result = "";
        int max_size = 0;
        weights[0] = 1;

        for (int i = 1; i < size; i++) {
            weights[i] = (i + 1) * weights[i - 1] + (i + 1);
            if (weights[i] > limit) {
                max_size = i - 1;
                break;
            }
        }
        int current_index = max_size;
        while (current_index >= 0) {
            if (weight >= weights[current_index]) {
                long int div = weight / weights[current_index];
                char current_char = 'A' + current_index;
                for (int i = 0; i < div; i++) {
                    result = current_char + result;
                }
                weight = weight - div * weights[current_index];
            }
            current_index--;
        }
        return result;
    }

};

int main()
{

    Solution question;
    question.smallestString(20);
   

    return 0;
}
