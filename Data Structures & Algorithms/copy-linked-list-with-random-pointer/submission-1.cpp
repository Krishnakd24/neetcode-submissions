/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* mover=head;
        unordered_map<Node*, Node*>mpp;

        Node* new_head=new Node(mover->val);
        Node* mover2=new_head;

        mpp[mover]=mover2;
        mover=mover->next;

        while(mover){
            Node* temp=new Node(mover->val);
            mover2->next=temp;
            mover2=mover2->next;

            mpp[mover]=mover2;

            mover=mover->next;
        }
        mover2=new_head;
        mover=head;
        while(mover2){
            mover2->random=mpp[mover->random];
            mover=mover->next;
            mover2=mover2->next;
        }
        return new_head;
    }
};
