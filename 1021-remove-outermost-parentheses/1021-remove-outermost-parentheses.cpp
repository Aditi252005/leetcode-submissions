class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();

        int count=0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') count++;
            if(count>1) st.push(s[i]);
            if(s[i]==')'){
                if(count==1) {count=0;continue;}
                count--;
            }
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};