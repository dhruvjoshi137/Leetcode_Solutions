/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        //Traverse the linked list with the fast and slow pointers
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next; //move fast two steps
            slow = slow->next; //move slow one step
            if(fast==slow){
                //Check if slow and fast pointers meet
                return true; //Loop detected
            }
        }
        //If fast reaches the end of the loop , there is no cycle
        return false;
    }
};