class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();

        int ans=0;
        
        stack<pair<int,int>> st;
        int l=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                l++;
            }else{
                int c=0;
                while(!st.empty() && st.top().second>l){
                    c+=st.top().first;
                    st.pop();
                }
                int score=(c==0)?1:2*c;
               
                st.push({score,l});
                l--;
            }
        }
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }

        return ans;
    }
};