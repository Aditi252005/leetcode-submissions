class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n=words.size();
        int m=words[0].length();
        map<string,int> mp;
        long long ans=0;

        for(int i=0;i<n;i++){
            string norm="";
            int shift=words[i][0]-'a';

            for(int j=0;j<m;j++){
                char c= (words[i][j]-'a'-shift+26)%26 +'a';
                norm.push_back(c);
            }
            ans+=mp[norm];
            mp[norm]++;
        }
        return ans;
    }
};