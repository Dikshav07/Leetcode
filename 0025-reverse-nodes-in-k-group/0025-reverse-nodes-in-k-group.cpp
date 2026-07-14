/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int step = 1;
        ListNode* temp = head;
        while(step < k && temp){
            step++;
            temp = temp->next;
        }
        if(!temp) return head;
        ListNode* next = temp->next;
        temp->next = NULL;
        ListNode* newHead = reverse(head);
        head->next = reverseKGroup(next, k);
        return newHead;

    }
};