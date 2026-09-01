class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const long long mod=1e9+7;

        vector<long long> count(n,0);
        stack<int> st;
        int ans=0;

        for(int i=0;i<n;i++){
            long long c=0;
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            
            if(st.empty()) c=1LL*(arr[i])*(i+1);
            else c=(long long)count[st.top()]+1LL*arr[i]*(i-st.top());

            count[i]=c%mod;
            ans=(ans+c)%mod;
            st.push(i);
        }

        
        return ans;
    }
};