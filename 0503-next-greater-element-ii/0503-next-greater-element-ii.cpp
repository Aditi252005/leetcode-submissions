class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++) nums.push_back(nums[i]);

        vector<int> ngi(n,-1);
        stack<int> st;

        for(int i=0;i<2*n;i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                if(st.top()<n) ngi[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }

        return ngi;
    }
};