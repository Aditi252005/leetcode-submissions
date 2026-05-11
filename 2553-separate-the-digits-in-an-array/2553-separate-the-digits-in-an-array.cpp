class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int j=0;

        for(int i=0;i<n;i++){
            int num=nums[i];
            while(num){
                int a=num%10;
                ans.push_back(a);
                num=num/10;
            }
            reverse(ans.begin()+j,ans.end());
            j=ans.size();
        }
        return ans;
    }
};