class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n=cit.size();
        sort(cit.begin(),cit.end());
        int ans=0;

        for(int i=0;i<n;i++){
            int num=n-i;
            ans=max(ans, min(num,cit[i]));
        }
        return ans;
    }
};