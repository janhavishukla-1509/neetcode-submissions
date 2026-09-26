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
        if(head == NULL || head->next == NULL){
            return;
        }
        ListNode* temp = head;
        while(temp->next != NULL && temp->next->next != NULL){
            ListNode* prev = temp;
            ListNode* curr = temp->next;
            while(curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            ListNode* stor = temp->next;
            temp->next = curr;
            curr->next = stor;
            temp = stor;
        }
    }
};
