class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* prev=head;
        ListNode* curr=head->next;
        int first=INT_MAX;
        int second=INT_MIN;
        int j=-1,k=-1;
        int i=1;

        while(curr->next){
            if((curr->val<prev->val && curr->val<curr->next->val) || (curr->val>prev->val && curr->val>curr->next->val)){
                if(j==-1) j=i;
                else {
                    first=min(first,i-j);
                    j=i;
                }
                if(k==-1) k=i;
                else second=max(second,i-k);
            }
            i++;
            prev=curr;
            curr=curr->next;
        }
        if(first==INT_MAX && second==INT_MIN) return {-1,-1};
        return {first,second};
    }
};