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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k==0) return head;
        int len = 1;
        ListNode* tmp = head;
        while(tmp->next) {
            tmp= tmp->next;
            len++;
        }
        tmp->next= head;
        k%=len;
        int steps = len-k;
        ListNode* NewTail= head;
        for(int i=1;i<steps;i++) {
            NewTail = NewTail->next;
        }
        ListNode* NewHead = NewTail->next;
        NewTail->next=nullptr;
        return NewHead; 
    }
};