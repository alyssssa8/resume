

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

class Solution3 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }

    }
};

class Solution4 {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int a = m - 1;
        int b = n - 1;
        int i = m + n - 1;
        while (a >= 0 && b >= 0) {
            if (A[a] > B[b]) {
                A[i--] = A[a--];
            }
            else {
                A[i--] = B[b--];
            }
        }
        while (b >= 0) {
            A[i--] = B[b--];
        }
    }


};

class Solution2 {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {


        int a = m - 1;
        int b = n - 1;
        int i = m + n - 1;    // calculate the index of the last element of the merged array

        // go from the back by A and B and compare and put to the A element which is larger
        while (a >= 0 && b >= 0) {
            if (A[a] > B[b])   A[i--] = A[a--];
            else            A[i--] = B[b--];
        }

        // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
        while (b >= 0)         A[i--] = B[b--];
    }


};


//use this one!
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = nums1.size() - 1;
        while (m - 1 >= 0 && n - 1 >= 0) {
            if (nums1[m - 1] < nums2[n - 1]) {
                nums1[size] = nums2[n - 1];
                n--;
            }
            else {
                nums1[size] = nums1[m - 1];
                m--;
            }
            size--;
        }

        if (n - 1 >= 0) {
            for (int i = n - 1; i >= 0; i--) {
                nums1[size] = nums2[i];
                size--;
            }

        }
    }
};

int main()
{
    vector<int>nums1({ 0 });
    vector<int>nums2({ 1 });
    Solution question;
    question.merge(nums1, 0, nums2, 1);
    /*   Solution question2;
       question2.merge(250);*/

    return 0;
}