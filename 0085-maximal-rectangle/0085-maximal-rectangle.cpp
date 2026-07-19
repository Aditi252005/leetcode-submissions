class Solution {
public:
    int f(vector<int>&height){
        int n=height.size();
        stack<int> st;
        int ans=0;

        for(int i=0;i<=n;i++){

            while(!st.empty() && (i==n || height[st.top()]>=height[i])){
                int h=height[st.top()];
                st.pop();

                int w;
                if(st.empty()) w=i;
                else w= i-st.top()-1;

                ans=max(ans,h*w);
            }
            st.push(i);
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<int> w(m,0);
        int maxArea=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='0') w[j]=0;
                else w[j]++;
            }

            maxArea=max(maxArea,f(w));
        }

        return maxArea;
    }
};