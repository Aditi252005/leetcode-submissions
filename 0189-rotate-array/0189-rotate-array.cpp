class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n=nums.size();
       k=k%n;
       int p=n-k-1;
       
       reverse(nums.begin(),nums.begin()+(p+1));
       reverse(nums.begin()+(p+1),nums.end());
       reverse(nums.begin(),nums.end());
    }
};