class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();

        int maxe=nums[n-1];
        vector<int> a;
        a.push_back(maxe);
        bool check=false;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<maxe){
                check=true;
                a.push_back(nums[i]);
                sort(a.begin(),a.end());
                int k=0;
                while(k<a.size()){
                    if(a[k]>nums[i]) {nums[i]=a[k];a[k]=0;break;}
                    k++;
                }
                sort(a.begin(),a.end());
                k=1;
                while(k<a.size()){
                    nums[i+k]=a[k];
                    k++;
                }
                
                break;
            }
            maxe=max(maxe,nums[i]);
            a.push_back(nums[i]);
        }

        if(!check) reverse(nums.begin(),nums.end());
    }
};