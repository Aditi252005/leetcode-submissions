class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int> st;

        int j=0;
        int i=0;
        while(j<n){
            if(st.size() && popped[j]==st.top()){
                st.pop();
                j++;
            }else{
                if(i==n) return false;
                else{
                    st.push(pushed[i]);
                    i++;
                }
            }
        }
        return true;
    }
};