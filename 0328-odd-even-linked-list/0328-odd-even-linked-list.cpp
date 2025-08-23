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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
    }
        ListNode* odd = head; //odd pointer -> starting point of the odd linked list
        ListNode* even = head->next; //even pointer -> starting point of the even linked list
        ListNode* evenHead = even; //store the starting point of the even linked list so that it 
        //could be attached at the end of odd linked list later ono
        while(even!=NULL && even->next!=NULL){
            odd->next = even->next; //odd's next should point to even's next which is an odd index
            odd = odd->next; //move odd to the next odd index
            even->next = odd->next;//even's next should point to odd's next which is an even index
            even = odd->next; //move even to the next even index
        }
        odd->next = evenHead; //attach the even index at the end of the odd index
        return head;
    }
};