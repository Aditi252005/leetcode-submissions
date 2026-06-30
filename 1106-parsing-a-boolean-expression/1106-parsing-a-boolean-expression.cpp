class Solution {
public:
    bool parseBoolExpr(string s) {
        int n=s.length();

        stack<char> op,st;
        bool ans;

        for(int i=0;i<n;i++){
            if(s[i]==',') continue;
            if(s[i]=='(' || s[i]=='f' || s[i]=='t') st.push(s[i]);
            else if(s[i]==')'){
                int a;
                if(st.top()=='f') a=0;
                else a=1;
                st.pop();

                char opr=op.top();
                op.pop();

                if(opr=='!'){
                    if(!st.empty() && st.top()=='(') st.pop();
                    if(a==0) st.push('t');
                    else st.push('f');
                    continue;
                }

                while(!st.empty() && st.top()!='('){
                    int b;
                    if(st.top()=='f') b=0;
                    else b=1;
                    st.pop();

                    if(opr=='&') a=a&b;
                    else if(opr=='|') a=a|b;
                }
                if(st.top()=='(') st.pop(); //popping (

                if(a==0) st.push('f');
                else st.push('t');
            }
            else op.push(s[i]);
        }


        if(st.top()=='f') return false;
        return true;
    }
};