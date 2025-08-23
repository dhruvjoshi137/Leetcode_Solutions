class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL; // agar 1 hi node hai, to wo hi delete ho jayegi
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next; // fast 2 steps
            prev = slow;             // prev slow ko track karega
            slow = slow->next;       // slow 1 step
        }

        // ab slow middle pe hai
        prev->next = slow->next; // middle ko list se hata do

        return head;
    }
};
