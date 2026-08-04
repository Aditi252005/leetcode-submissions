class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        set<int> st;

        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
             st.insert(nums[i]);
             mini=min(nums[i],mini);
             maxi=max(nums[i],maxi);
        }

        for(int i=mini+1;i<maxi;i++){
            if(st.find(i)==st.end()) ans.push_back(i);
        }
        return ans;
        
    }
};