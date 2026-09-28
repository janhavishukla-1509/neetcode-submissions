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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int s = carry;
            if(l1 != NULL){
                s += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                s += l2->val;
                l2 = l2->next;
            }
            carry = s / 10;
            ListNode* newNode = new ListNode(s % 10);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
        }
        return head;
    }
};
