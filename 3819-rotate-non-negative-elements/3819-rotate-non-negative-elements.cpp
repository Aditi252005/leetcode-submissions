class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v;

        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                v.push_back(nums[i]);
                nums[i]=1e9;
            }
        }

        if(v.size()>=1){
            k=k%v.size();
            rotate(v.begin(),v.begin()+k,v.end());
        }
       // for(auto i:v) cout<<i;
        int j=0;

        for(int i=0;i<n;i++){
            if(nums[i]==1e9){
                nums[i]=v[j];
                j++;
            }
        }


        return nums;


    }
};