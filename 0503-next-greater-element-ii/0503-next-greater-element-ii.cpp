class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) nums.push_back(nums[i]);

        vector<int> ans(n,-1);
        stack<int> st;

        for(int i=0;i<2*n;i++){

            while(!st.empty() && nums[i]>nums[st.top()]){
                if(ans[st.top()%n]==-1) ans[st.top()%n]=nums[i];
                st.pop();
            }

            st.push(i);
        }
        return ans;
    }
};