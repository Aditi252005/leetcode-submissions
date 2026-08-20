class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.length();
        int m=station.length();

        vector<int> fo(n);
        vector<int> lo(n);
        int i=0;
        for(int j=0;j<m&&i<n;j++){
            if(skill[i]==station[j]) {fo[i]=j;i++;}
        }
        i=n-1;
        for(int j=m-1;j>=0&&i>=0;j--){
            if(skill[i]==station[j]) {lo[i]=j;i--;}
        }

        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,lo[i]-fo[i-1]);
        }
        return ans;
    }
};