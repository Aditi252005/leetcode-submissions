class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<char> st;

        for(int i=0;i<n;i++){
            char ch=num[i];
            while(!st.empty() && k>0 && ch<st.top()) {st.pop();k--;}
            st.push(ch);
        }

        
        while(k--) st.pop();
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0') i++;
        ans=ans.substr(i,ans.length());

        if(ans.length()==0) return "0";        
        return ans;
    }
};