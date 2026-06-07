class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<int> ans(n,-1);
        map<int,int> mp;
        stack<int> st;
        for(int i=0;i<n;i++) mp[nums1[i]]=i;

        for(int i=0;i<m;i++){

            while(!st.empty() && nums2[i]>st.top()){
                if(mp.find(st.top())!=mp.end()){
                    ans[mp[st.top()]]=nums2[i];
                }
                st.pop();
            }

            st.push(nums2[i]);
        }
        return ans;
    }
};