class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();

        stack<char> st;
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                if(count==1){
                    if(st.empty()) ans+=2;
                    else {ans++;st.pop();}
                    count=0;
                }

                st.push(s[i]);
            }
            else{
                count++;
                if(count==2){
                    if(st.empty()) ans++;
                    else st.pop();
                    count=0;
                }
            }
        }
        if(!st.empty() && count) ans+=st.size()*2 -count;
        if(!st.empty() && !count) ans+=st.size()*2;
        if(st.empty() && count && count%2==0) ans+=count/2;
        else if(st.empty() && count && count%2==1) ans+=count/2 +2;

        return ans;
    }
};