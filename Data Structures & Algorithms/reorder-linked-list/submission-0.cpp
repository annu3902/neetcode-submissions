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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        
        // 1. Middle of LL
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow stops at middle node
        ListNode* temp = slow->next;
        slow->next = NULL;

        // 2. Reverse the LL
        ListNode* curr = temp;
        ListNode* prev = NULL;
        ListNode* next = curr->next;

        while(next){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;

        // 3. 
        ListNode* first = head;
        ListNode* second = curr;
        ListNode* firstNext = first->next;
        ListNode* secondNext = second->next;

        while(firstNext && secondNext){
            second->next = firstNext;
            first->next = second;
            first = firstNext;
            second = secondNext;
            firstNext = firstNext->next;
            secondNext = secondNext->next;
        }

        while(firstNext){
            second->next = firstNext;
            first->next = second;
            second = secondNext;
            first = firstNext;
            firstNext = firstNext->next;
        }

        if(second){
            second->next = firstNext;
            first->next = second;
        }

    }
};
