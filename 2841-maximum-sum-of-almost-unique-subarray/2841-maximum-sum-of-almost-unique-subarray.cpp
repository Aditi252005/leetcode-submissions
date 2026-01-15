class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n=nums.size();
        long long ans=0;

       
        map<int,int> mp;
        long long sum=0;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            sum+=nums[i];
        } 
        
        int i=0;
        int j=k;

        while(j<n){
            if(mp.size()>=m) ans=max(ans,sum);
            sum-=nums[i];
            sum+=nums[j];
            mp[nums[j]]++;
            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);
            //cout<<j<<mp.size()<<endl;
            j++;
            i++;
        }
        if(mp.size()>=m) ans=max(ans,sum);
        return ans;
    }
};