
//https://www.codecademy.com/



/*


 //Definition for a binary tree node.



 //ListNode head6(1); //only a variable

 ListNode * head5 = new ListNode(10); //this is a pointer,

 ListNode * head4 = new ListNode(9);
 head4->next = head5;
 ListNode * head3 = new ListNode(8);
 head3->next = head4;
 ListNode * head2 = new ListNode(4);
 head2->next = head3;
 ListNode * head = new ListNode(2);
 head->next = head2;


 ListNode * head11 = new ListNode(10);
 ListNode * head10 = new ListNode(9);
 head10->next = head11;
 ListNode * head9 = new ListNode(8);
 head9->next = head10;
ListNode * head8 = new ListNode(5);
head8->next = head3;
ListNode * head7 = new ListNode(3);
head7->next = head8;
ListNode * head6 = new ListNode(1);
head6->next = head7;


TreeNode tree1(1);
TreeNode tree2(2);
TreeNode tree3(3);
TreeNode tree4(4);
TreeNode tree5(5);
TreeNode tree6(6);
TreeNode tree7(7);

TreeNode tree10(1);
TreeNode tree20(2);
TreeNode tree30(3);
TreeNode tree40(4);
TreeNode tree50(5);
TreeNode tree60(6);
TreeNode tree70(7);


tree1.left = &tree2; // & to get the address of something
tree1.right = &tree3;
tree2.left = &tree4; // & to get the address of something
tree2.right = &tree5;
tree3.left = &tree6; // & to get the address of something
tree3.right = &tree7;

tree10.left = &tree20; // & to get the address of something
tree10.right = &tree30;
tree20.left = &tree40; // & to get the address of something
tree20.right = &tree50;
tree30.left = &tree60; // & to get the address of something
tree30.right = &tree70;




struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



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





int main()
{

	vector<int>nums({ 3, 1 ,0 });
	Solution question;	
	question.sortedArrayToBST(nums);
	Solution2 question2;
	question2.sortedArrayToBST(nums);

    return 0;
}


*/
//For a given source string and a target string, you should output the first index(from 0) of 
//target string in source string.
//If target does not exist in source, just return -1.
//Clarification
//Do I need to implement KMP Algorithm in a real interview ?
//
//Not necessary.When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability.But make sure you confirm with the interviewer first.
//Example
//If source = "source" and target = "target", return -1.
//
//If source = "abcdabcdefg" and target = "bcd", return 1.


//https://www.jiuzhang.com/solution/strstr/
//http://www.lintcode.com/en/problem/strstr/
//https://leetcode.com/problems/implement-strstr/discuss/12956/Explained-4ms-Easy-C++-solution
//https://yisuang1186.gitbooks.io/-shuatibiji/closest_number_in_sorted_array.html


// source: "", "aa"  ""  "aa"
// target:  a , "a"  ""   ""
// return: -1,   0    0    0




#include <iostream>
using namespace std;

int strStr(string haystack, string needle);

int main()
{
   
    string haystack = "aaa", targetChar = "a";
    
    strStr(haystack, targetChar);
    


}


//think about the null  for source and target
//
int strStr (string haystack, string needle)
{
  
    int haystackLength = haystack.length();
    int needleLength = needle.length();
    // if target is empty, then return the 0 index. 
    if (!needleLength)  //if needlelength = 0, which means false, !false is true, if it is 0, then return 0. the first index position. 
    {
        return 0;
    }
    for (int i = 0; i < haystackLength - needleLength + 1; i++)
    {
        int j = 0;//because of line 88
        for (j = 0; j < needleLength; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                break;//break out 1 loop, will go back to the first for loop. 
            }
        }
        if (j == needleLength)
        {
            return i;
        }     
       
    }
    return -1;
}


