class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n);
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            int p=nums[i]; 
            int maxp=nums[i];//0 //2
            for(int j=i+1;j<n;j++){
                p=p*nums[j]; //0
                maxp=max(maxp,p); //0
            }
           
            v[i]=maxp; //0
        }
        sort(v.begin(),v.end());
        return v[n-1];
    }
};