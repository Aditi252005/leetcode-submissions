class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<char> st;

       
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                string a;
                while(st.top()!='('){
                    a.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(int j=0;j<a.length();j++) st.push(a[j]);
            }
            else st.push(s[i]);
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