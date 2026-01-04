class Solution {
public:
    void check(int a,int& count){
        int d1=0,d2=0;
        for(int i=2;i<=a/2;i++){
            if(a%i==0 && !d1) d1=i;
            else if(a%i==0 && d1 && !d2) d2=i;
            else if(a%i==0 && d1 && d2){
                d1=0;
                break;
            }
        }
        if(d1 && d2) count+=d1+d2+1+a;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int count=0;

        for(int i=0;i<n;i++){
            check(nums[i],count);
        }
        return count;
    }
};