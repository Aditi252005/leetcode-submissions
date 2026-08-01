class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.length();
        map<char,int> mp1,mp2;
        for(auto ch:s1) mp1[ch]++;

        int i=0;
        int j=0;
        while(j<n){
            mp2[s2[j]]++;
            bool check=true;
            for(auto it:mp1){
                if(mp2[it.first]<it.second){check=false;break;}
            }

            if(check){
                while(i<j && mp2[s2[i]]>mp1[s2[i]]){
                    mp2[s2[i]]--;
                    i++;
                }

                if(j-i+1==s1.length()) return true;
            }
            j++;
        }
        return false;
    }
};