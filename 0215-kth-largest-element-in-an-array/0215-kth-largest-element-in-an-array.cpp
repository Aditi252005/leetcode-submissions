class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();

        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }

        while(k--){
            int num=pq.top();
            pq.pop();
            if(k==0) return num;
        }
        return -1;
    }
};