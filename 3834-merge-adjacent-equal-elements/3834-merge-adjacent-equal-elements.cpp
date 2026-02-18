class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        vector<long long> a;
        stack<long long> st;
        
        int j=0;
        while(j<n){
            long long p=nums[j];
            while(!st.empty() && st.top()==p){
                st.pop();
                p=2*p;                
            }
            st.push(p);
            j++;
        }
        while(!st.empty()){
            a.push_back(st.top());
            st.pop();
        }
        reverse(a.begin(),a.end());

        return a;
    }
};