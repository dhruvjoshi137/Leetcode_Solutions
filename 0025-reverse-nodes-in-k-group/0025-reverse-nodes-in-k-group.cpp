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

    ListNode* reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp , int k){
        k-=1; //pehle hi k ko decrement kardo kyunki we are starting from first node itself
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
            //jaise hi mera k = 0 ho jayega , i will reach my required node and i will return the temp
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp!=NULL){
            ListNode* kthNode = getKthNode(temp,k);
            if(kthNode==NULL){
                if(prevNode){
                    prevNode->next = temp;
                    break;
                }
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseLL(temp);
            if(temp==head){
                //this means it is the first group
                head = kthNode;
            }else{
                prevNode->next = kthNode;
              
            }
            prevNode = temp;
            temp = nextNode; 
        }
        return head;
    }
};