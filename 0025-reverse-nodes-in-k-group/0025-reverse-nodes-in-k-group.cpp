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
    // Helper function: reverse a linked list and return new head
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; // new head
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;

        ListNode* revStart = nullptr;       // start of sublist
        ListNode* revStartPrev = nullptr;   // node before sublist
        ListNode* revEnd = nullptr;         // end of sublist
        ListNode* revEndNext = nullptr;     // node after sublist

        int i = 1;
        ListNode* currNode = head;

        while (currNode && i <= n) {
            if (i < m) revStartPrev = currNode;
            if (i == m) revStart = currNode;
            if (i == n) {
                revEnd = currNode;
                revEndNext = currNode->next;
            }
            currNode = currNode->next;
            i++;
        }

        // break link
        revEnd->next = nullptr;

        // reverse sublist
        ListNode* newSubHead = reverseList(revStart);

        // reattach
        if (revStartPrev != nullptr) {
            revStartPrev->next = newSubHead;
        } else {
            head = newSubHead; // sublist started from head
        }

        revStart->next = revEndNext; // old start is now end

        return head;
    }


   ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prevGroupEnd = &dummy;

    while (true) {
        // check if at least k nodes exist
        ListNode* kth = prevGroupEnd;
        for (int i = 0; i < k && kth != nullptr; i++) {
            kth = kth->next;
        }
        if (kth == nullptr) break; // less than k nodes left

        // reverse k nodes
        ListNode* groupStart = prevGroupEnd->next;
        ListNode* nextGroupStart = kth->next;

        // detach group
        kth->next = nullptr;

        // reverse group
        ListNode* newGroupHead = reverseList(groupStart);

        // reattach
        prevGroupEnd->next = newGroupHead;
        groupStart->next = nextGroupStart;

        // move prevGroupEnd
        prevGroupEnd = groupStart;
    }

    return dummy.next;
}
};