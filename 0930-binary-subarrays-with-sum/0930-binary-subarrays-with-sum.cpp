class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();

        int j=0;
        int i=0;
        int ans=0;
        int curs=0;

        while(j<n){
            curs+=nums[j];
            if(curs>=goal){
                i=0;
                int s=curs;
                while(i<=j && s>goal) {s=s-nums[i];i++;}
                while(i<=j && s==goal) {ans++;s=s-nums[i];i++;}
            }
            j++;
        }
        return ans;
    }
};