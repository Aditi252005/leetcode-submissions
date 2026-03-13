class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[numbers[i]]=i;

        for(int i=0;i<n;i++){
            int t=target-numbers[i];
            if(mp.find(t)!=mp.end()){
                return {i+1,mp[t]+1};
            }
        }
        return {1,2};
    }
};