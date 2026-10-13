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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) return nullptr;
        reverse(head);

        ListNode *prev = nullptr;
        ListNode *toDelete = head;
        while (toDelete && toDelete->next && (--n > 0)) {
            prev = toDelete;
            toDelete = toDelete->next;
        }

        if (prev) {
            prev->next = toDelete->next;
            toDelete->next = nullptr;
            delete toDelete;
        } else {
            head = toDelete->next;
            toDelete->next = nullptr;
            delete toDelete;
        }

        reverse(head);
        return head;
    }
private:
    void reverse(ListNode *&head) {
        if (!head || !head->next) return;

        ListNode *prev{nullptr};
        ListNode *curr = head;

        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
};
