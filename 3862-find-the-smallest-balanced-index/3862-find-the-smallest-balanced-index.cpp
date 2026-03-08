class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();

        vector<long long> pre(n);
        pre[0]=0;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }

        long long p=1;
    
        for(int i=n-1;i>=0;i--){
            if(p==pre[i]) return i;
            else if(p>1e14){
                break;
            }
            p=(p*nums[i]);
        }
        return -1;

    }
};