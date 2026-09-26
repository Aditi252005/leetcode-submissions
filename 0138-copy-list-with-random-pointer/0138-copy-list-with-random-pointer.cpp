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
        Node* dummy= new Node(-1);
        Node* t1=head;
        Node* t2=dummy;
        unordered_map<Node*,Node*> mp;
        
        while(t1){
            Node* a= new Node(t1->val);
            t2->next=a;

            mp[t1]=a;

            t1=t1->next;
            t2=t2->next;
        }
        
        t2=dummy->next;
        t1=head;
        while(t2){
            if(t1->random) t2->random=mp[t1->random];
            t1=t1->next;
            t2=t2->next;
        }
        return dummy->next;
    }
};