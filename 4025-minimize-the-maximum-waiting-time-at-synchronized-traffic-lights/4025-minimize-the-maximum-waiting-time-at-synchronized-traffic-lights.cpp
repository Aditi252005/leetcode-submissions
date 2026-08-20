class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& time) {
        int n=time.size();
        for(int i=0;i<n;i++) time[i]=time[i]%period;

        int m=lights.size();
        sort(lights.begin(),lights.end());

        int ans=0;
        for(int i=0;i<n;i++){
            if(time[i]<lights[m-1]) continue;
            else ans=max(ans,period-time[i]);
        }
        return ans;
    }
};