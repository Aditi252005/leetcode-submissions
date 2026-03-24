class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int ans=0;
        stack<char> st;
        s.push_back('(');
        int bal=0;

        for(int i=0;i<n+1;i++){
            if(s[i]=='('){
                if(bal==1){
                    if(!st.empty()){
                        ans++;
                        st.pop();
                    }else{
                        ans+=2;
                    }
                    bal=0;
                }
               st.push('(');
            }
            else if(s[i]==')'){
                bal++;
                if(bal==2){
                    if(!st.empty()) st.pop();
                    else ans++;
                    bal=0;
                }
            }
        }
        return ans + (st.size()-1)*2;
    }
};