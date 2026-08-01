class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();

        int lo=*max_element(weights.begin(),weights.end());
        int hi=accumulate(weights.begin(),weights.end(),0);

        while(lo<hi){
            int d=days;
            int mid=lo+(hi-lo)/2;
            int s=0;
            bool check=true;

            for(int i=0;i<n;i++){
                if(d==0) {check=false;break;}
                if(s+weights[i]<=mid) s+=weights[i];
                else {d--;s=weights[i];}
            }

            //cout<<lo<<mid<<hi<<check<<endl;
            if(check && d>0) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};