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
    ListNode* reverse(ListNode* head){
          ListNode* prev = NULL;

        while(head){
            ListNode* nexxt = head->next;
            head->next = prev;
            prev = head;
            head = nexxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ans = adder(l1 , l2);
        return reverse(ans);
    }

    ListNode* adder(ListNode* l1 , ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        int carry = 0;

        while(l1 != nullptr || l2!=nullptr || carry !=0){
            int digi1 = (l1 != nullptr) ? l1->val : 0;
            int digi2 = (l2!=nullptr) ? l2->val : 0;

            int sum = digi1 + digi2 + carry;
            int digit = sum%10;
            carry = sum/10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;

        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};