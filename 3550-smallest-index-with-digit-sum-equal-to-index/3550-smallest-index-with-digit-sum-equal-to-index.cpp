class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int m=nums[i];
            int s=0;
            while(m){
                s+=m%10;
                m=m/10;
            }
            if(s==i) return i;
        }
        return -1;
    }
};