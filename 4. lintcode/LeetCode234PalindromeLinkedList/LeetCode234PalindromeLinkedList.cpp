//
//
//https://leetcode.com/problems/palindrome-linked-list/description/
//
//Given a singly linked list, determine if it is a palindrome.
//
//Example 1 :
//
//	Input : 1->2
//	Output : false
//	Example 2 :
//
//	Input : 1->2->2->1
//	Output : true
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
using namespace std;





 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
 public:
	 bool isPalindrome(ListNode* head) {

		 stack<int> tempStack;
		 ListNode* newStore = head;
		 ListNode* fast = head;
		 ListNode* newHead;

		 if (head == NULL) {
			 return true;
		 }
		 while (fast != NULL) {  //[1,2,1], [1,2,2,1] 

			 if (fast->next == NULL) {
				 newHead = newStore->next;
				 fast = NULL;
			 }
			 else if (fast->next->next == NULL) { //[1,2]
				 newHead = newStore->next;
				 tempStack.push(newStore->val);
				 fast = NULL;
			 }
			 else {
				 tempStack.push(newStore->val);
				 newStore = newStore->next;
				 fast = fast->next->next;

			 }
		 }
		 while (newHead != NULL && newHead->val == tempStack.top()) {
			 newHead = newHead->next;
			 tempStack.pop();
		 }
		 if (tempStack.empty() == true) {
			 return true;
		 }
		 else {
			 return false;
		 }

	 }
 };
 class Solution {
 public:
	 bool isPalindrome(ListNode* head) {
		 stack<int> tempStack;
		 ListNode* newStore = head;
		 ListNode* fast = head;

		 if (head == NULL) {
			 return true;
		 }

		 while (fast != NULL) {

			 if (fast->next == NULL) {
				 newStore = newStore->next;
				 break;
			 }
			 else if (fast->next->next == NULL) {

				 tempStack.push(newStore->val);
				 newStore = newStore->next;
				 break;
			 }
			 else {
				 tempStack.push(newStore->val);
				 fast = fast->next->next;
				 newStore = newStore->next;
			 }
		 }
		 while (newStore != NULL && newStore->val == tempStack.top()) {
			 tempStack.pop();
			 newStore = newStore->next;
		 }
		 if (tempStack.empty() == true) {
			 return true;
		 }
		 else {
			 return false;
		 }

	 }
 };
class Solution2 {
public:
	bool isPalindrome(ListNode* head) {

		stack<int> st;
		ListNode* h = head;
		ListNode* hh = head;

		while (h) {
			st.push(h->val);
			h = h->next;

		}

		while (hh && hh->val == st.top()) {
			hh = hh->next;
			st.pop();
		}
		if (st.empty())  return true;
		else            return false;

	}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		int len = 0, i = 0;
		struct ListNode* p = head;
		while (p) {
			len++;
			p = p->next;
		}
		int* nums = (int*)malloc(sizeof(int)*len);
		p = head;
		while (p) {
			nums[i++] = p->val;
			p = p->next;
		}
		for (i = 0; i<len / 2; i++) {
			if (nums[i] != nums[len - i - 1])
				return false;
		}
		return true;
	}
};



int main()
{


	ListNode head6(1); //only a variable

	ListNode * head5 = new ListNode(12); //this is a pointer, 

	ListNode * head4 = new ListNode(3);
	head4->next = head5;
	ListNode * head3 = new ListNode(0);
	head3->next = head4;
	ListNode * head2 = new ListNode(3);
	head2->next = head3;
	ListNode * head = new ListNode(0);
	head->next = head2;


	Solution question;
	question.isPalindrome(head);
	Solution2 question2;
	question2.isPalindrome(head);


	return 0;
}