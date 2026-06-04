class Solution {
public:
    int countGoodNumbers(long long n) {
        long long int mod=1e9+7;
        long long oidx= n/2;
        long long eidx= n- oidx;
        long long ans=1;
        long long o=4;
        long long e=5;

        while(oidx){
            if(oidx%2==1) ans=(ans*o)%mod;
            o=(o*o)%mod;
            oidx=oidx/2;
        }
        while(eidx){
            if(eidx%2==1) ans=(ans*e)%mod;
            e=(e*e)%mod;
            eidx=eidx/2;
        }
        return ans;
    }
};