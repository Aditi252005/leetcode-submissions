class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<pair<int,int>> st;
        int ans=0;

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first<height[i]){//3
                int c=st.top().first;//2
                st.pop();//4
                if(st.empty())break;  
                ans+=(min(height[i],st.top().first)-c)*(i-st.top().second-1);//2
                
            }
           
            st.push({height[i],i});
        }
        return ans;
    }
};