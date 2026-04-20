class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ans=0;
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[colors[i]]=i;

        int i=0;
        while(i<n){
            int j=n-1;
            while(colors[j]==colors[i]) j--;
            ans=max(ans,j-i);
            i++;
        }
        return ans;
    }
};