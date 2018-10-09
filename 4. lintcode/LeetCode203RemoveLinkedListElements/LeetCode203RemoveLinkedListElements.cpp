//
//https://leetcode.com/problems/remove-linked-list-elements/description/
//
//Remove all elements from a linked list of integers that have value val.
//
//Example :
//
//	Input : 1->2->6->3->4->5->6, val = 6
//	Output : 1->2->3->4->5
//
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
#include <unordered_set>
#include <set>
using namespace std;





//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// if the target is the last element, will not have node->next = node->next->next. 
class Solution {
public:
	ListNode * removeElements(ListNode* head, int val) {
		ListNode *ansHead = new ListNode(0);
		ansHead->next = head; // with out empty node here,[1,2,6,3,4,5,6] if delete 6, it do not have cur ->next->next, so need to put a empty node in the beginning. 
		
		ListNode *cur = ansHead;
		while (cur) {
			if (cur->next && cur->next->val == val) {  // before and after &&, must have this order. 
				cur->next = cur->next->next;
			}

			else {
				cur = cur->next;
			}
		}
		return ansHead->next;
	}
};


int main()
{

	//ListNode head6(1); //only a variable
	ListNode * head7 = new ListNode(6);

	ListNode * head6 = new ListNode(4); //this is a pointer, 
	head6->next = head7;								//head6->next = head7;
	ListNode * head4 = new ListNode(3);
	head4->next = head6;
	ListNode * head3 = new ListNode(6);
	head3->next = head4;
	ListNode * head2 = new ListNode(2);
	head2->next = head3;

	ListNode * head = new ListNode(1);
	head->next = head2;


	Solution question;
	question.removeElements(head,6);

	//Solution2 question2;
	//question2.mergeTwoLists(head, head);


	return 0;
}