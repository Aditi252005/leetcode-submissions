class Solution {
public:
    ListNode* merge(ListNode* list1,ListNode*list2){
        ListNode* temp1=list1;
        ListNode* temp2=list2;
       
        ListNode* head=new ListNode(INT_MIN);
        ListNode* curr=head;

        while(temp1 && temp2){
            if(temp1->val<=temp2->val){
                curr->next=temp1;
                curr=curr->next;
                temp1=temp1->next;
            }else{
                curr->next=temp2;
                curr=curr->next;
                temp2=temp2->next;
            }
        }

        while(temp1){
            curr->next=temp1;
            curr=curr->next;
            temp1=temp1->next;
        }
        while(temp2){
            curr->next=temp2;
            curr=curr->next;
            temp2=temp2->next;
        }

        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(!n) return NULL;

        ListNode* list1=lists[0];
        ListNode* list2=NULL;
        if(n>1) list2=lists[1];

        list1=merge(list1,list2);

        for(int i=2;i<n;i++){
            list2=lists[i];
            list1=merge(list1,list2);
        }

        return list1;
    }
};