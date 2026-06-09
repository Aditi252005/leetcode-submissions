class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        int ans=0;
        int j=0;
        int i=0;
        int p=0;
        int odd=0;

        while(j<n){
            if(nums[j]%2==1) odd++;

            if(odd==k){
                i=p;
                while(i<j && nums[i]%2==0) {i++;ans++;}
                ans++;
            }
            if(odd>k){
                p=i+1;
                i=p;
                while(i<j && nums[i]%2==0) {i++;ans++;}
                ans++;
                odd--;
            }
            j++;
        }
        return ans;
    }
};