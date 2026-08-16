class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        vector<int> v(3,0);

        for(int i=0;i<n;i++) v[stones[i]%3]++;

        if(v[0]%2==0) return v[1]>0 && v[2]>0;
        return abs(v[1]-v[2])>2;
    }
};