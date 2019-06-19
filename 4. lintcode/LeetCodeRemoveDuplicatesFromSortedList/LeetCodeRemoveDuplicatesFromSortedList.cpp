

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
#include<set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* traverse = head;
        while (traverse != NULL) {
            while (traverse->next != NULL && traverse->val == traverse->next->val) {
                traverse->next = traverse->next->next;
            }
            traverse = traverse->next;
        }
        return head;
    }
};
int main()
{
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
    Solution question;
    vector<int> num1({ 0,0,2,2 });
    vector<int> num2({ 1,1,3,3 });
    question.deleteDuplicates(head);
    return 0;
}

