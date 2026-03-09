class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();

        stack<int> st;

        for(int i=0;i<n;i++){
           int curr=asteroids[i];
           bool same=false;
           bool isSmall=false;
            while(!st.empty() && st.top()>0 && curr<0){
                if(st.top()==abs(curr)){               
                    st.pop();
                    same=true;
                    break;
                }
                else if(st.top()<abs(curr)) st.pop();
                else{
                    isSmall=true;
                    break;
                }                
            }
            if(!same && !isSmall) st.push(curr);
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};