class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int start=0,ans=0;
        for(int i=0;i<n;i++){
            start=start+gain[i];
            ans=max(ans,start);
        }
        return ans;
    }
};