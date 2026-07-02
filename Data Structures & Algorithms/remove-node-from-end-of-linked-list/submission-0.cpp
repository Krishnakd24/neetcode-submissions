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
        int l=0;
        if(!head) return head;
        ListNode* mover=head;
        while(mover){
            l++;
            mover=mover->next;
        }
        int k=l-n;
        mover=head;
        if(k==0) return head->next;
        while(--k) mover=mover->next;
        ListNode* temp=mover->next;
        mover->next=mover->next->next;
        delete temp;
        return head;

    }
};
