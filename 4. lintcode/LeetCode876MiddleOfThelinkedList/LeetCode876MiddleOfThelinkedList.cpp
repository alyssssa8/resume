
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




//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
int main()
{


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
    vector<int>nums({ 3, 1 ,0 });
    Solution question;
    question.middleNode(head);
    Solution question2;
    question2.middleNode(head10);

    return 0;
}