class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long s=mass;
        for(int i=0;i<n;i++){
            if(asteroids[i]>s) return false;
            s+=asteroids[i];
        }
        return true;
    }
};