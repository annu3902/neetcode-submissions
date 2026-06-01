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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;
        else if(!list2) return list1;
        else if(!list1) return list2;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* head = NULL;
        ListNode* curr = head;

        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                if(head == NULL){
                    head = new ListNode(temp1->val);
                    curr = head;
                }else{
                    ListNode* temp = new ListNode(temp1->val);
                    curr->next = temp;
                    curr = temp;
                }
                temp1 = temp1->next;
            }else{
                if(head == NULL){
                    head = new ListNode(temp2->val);
                    curr = head;
                }else{
                    ListNode* temp = new ListNode(temp2->val);
                    curr->next = temp;
                    curr = temp;
                }
                temp2 = temp2->next;
            }
        }

        while(temp1){
            ListNode* temp = new ListNode(temp1->val);
            curr->next = temp;
            curr = temp;
            temp1 = temp1->next;
        }

        while(temp2){
            ListNode* temp = new ListNode(temp2->val);
            curr->next = temp;
            curr = temp;
            temp2 = temp2->next;
        }

        return head;
    }
};
