//https://leetcode.com/problems/linked-list-cycle/description/
//https://www.youtube.com/watch?v=qckKEYP9bBA
//http://zxi.mytechroad.com/blog/leetcode/leetcode-21-merge-two-sorted-lists/
//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?


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

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != NULL) { // pay attention on this line
			if (fast->next == NULL) { // pay attention on this line
				return false;
			}
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				return true;
			}
		}
		return false;

	}
};

class Solution2 {
public:
	bool hasCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast) {
			if (!fast->next) return false;
			fast = fast->next->next; // 1,2,//2's next could be NULL
			slow = slow->next;
			if (fast == slow) return true;
		}	
		return false;

	}
};
class Solution {
public:
	bool hasCycle(ListNode *head) {
		unordered_set<ListNode *> visited;
		while (head) {
			if (visited.count(head)) {
				return true;  //Searches the container for elements equivalent to val and returns the number of matches.
			}
			visited.insert(head);
			head = head->next;
		}

		return false;


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
	head5->next = head2;
	ListNode * head = new ListNode(0);
	head->next = head2;

	
	Solution question;
	question.hasCycle(head);


	return 0;
}