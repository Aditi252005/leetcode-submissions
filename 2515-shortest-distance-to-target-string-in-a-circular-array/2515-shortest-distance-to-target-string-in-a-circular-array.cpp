class Solution {
public:
    int closestTarget(vector<string>& words, string t, int idx) {
        int n=words.size();
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(words[i]==t) ans=min({ans,abs(i-idx),abs(n-abs(i-idx))});
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};