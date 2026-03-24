class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<pair<char,int>> st;
        string ans;

        for(int i=0;i<n;i++){  //)
            if(s[i]=='('){
                st.push({'(',i});
            }else if(s[i]==')'){
                if(!st.empty() && st.top().first=='(') st.pop();
                else st.push({')',i});
            }
        }

        for(int i=n-1;i>=0;i--){
            if(!st.empty() && st.top().second==i) st.pop();
            else ans.push_back(s[i]);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};