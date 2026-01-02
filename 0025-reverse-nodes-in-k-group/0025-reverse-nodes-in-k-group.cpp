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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* curr = head;
        ListNode* prevGroupEnd = nullptr;
        bool firstGroup = true;

        while (curr) {
            // check if there are k nodes
            ListNode* check = curr;
            for (int i = 0; i < k; i++) {
                if (!check) return head;
                check = check->next;
            }

            // reverse k nodes
            ListNode* groupHead = curr;
            for (int i = 1; i < k; i++) {
                ListNode* next = curr->next;

                curr->next = next->next;
                next->next = groupHead;
                groupHead = next;
            }

            // connect groups
            if (firstGroup) {
                head = groupHead;
                firstGroup = false;
            } else {
                prevGroupEnd->next = groupHead;
            }
            prevGroupEnd = curr;
            curr = curr->next;
        }

        return head;
    }
};