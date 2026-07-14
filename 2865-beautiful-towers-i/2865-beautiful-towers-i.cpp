class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n=heights.size();

        long long ans=0;
        for(int i=0;i<n;i++){
            vector<int> h(n);
            h[i]=heights[i];

            for(int j=i-1;j>=0;j--){
                h[j]=min(heights[j],h[j+1]);
            }
            
            for(int j=i+1;j<n;j++){
                h[j]=min(heights[j],h[j-1]);
            }
            
            long long count=0;
            for(auto x:h) count+=x;

            ans=max(ans,count);
        }

        return ans;
    }
};