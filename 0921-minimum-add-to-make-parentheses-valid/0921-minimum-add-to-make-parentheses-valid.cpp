class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        int count=0;
        stack<char> st;


        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
                // count++;
            } 
            else{
                if(!st.empty()){
                  st.pop(); 
                  count++;   
                }
                count--;
            } 
        }
        return abs(count)+st.size();
    }
};