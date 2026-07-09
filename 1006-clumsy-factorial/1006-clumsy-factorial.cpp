class Solution {
public:
    int clumsy(int num) {
        
        vector<char> op={'*','/','+','-'};
        stack<int> st;
        st.push(num);

        int i=0;
        int n=num-1;
        while(n>0){
            int a=st.top();
            int b=n;
            st.pop();

            char opr= op[i%4];
            if(opr=='*') st.push(a*b);
            else if(opr=='/') st.push(a/b);
            else if(opr=='+') st.push(a+b);
            else{
                if(b>=3) {st.push(a- ((b*(b-1))/(b-2))); n-=2;i+=2;}
                else if(b==2) {st.push(a- (b*(b-1)));break;}
                else {st.push(a-b);break;}
            }
            n--;
            i++;
        }

        return st.top();
    }
};