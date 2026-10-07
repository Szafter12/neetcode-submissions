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
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* first_half = head;
        ListNode* second_half = reverse(slow->next);
        slow->next = nullptr;

        while(second_half) {
            ListNode* next_tmp1 = first_half->next;
            ListNode* next_tmp2 = second_half->next;

            first_half->next = second_half;
            second_half->next = next_tmp1;

            first_half = next_tmp1;
            second_half = next_tmp2;
        }
    }

private:
    ListNode* reverse(ListNode* head) {
        if (!head) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
