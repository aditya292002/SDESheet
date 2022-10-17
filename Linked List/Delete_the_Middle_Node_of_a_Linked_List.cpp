
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* &head) {
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        ListNode* fast = temp;
        ListNode* slow = temp;
        if(head->next == NULL) return NULL;
        while(fast->next != NULL and fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};


int main () {
}