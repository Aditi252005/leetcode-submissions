class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long, vector<long long>, greater<>> pq;

        for(auto num:nums) pq.push(num);
        int ans=0;

        while(!pq.empty()){
            long long a=pq.top();
            pq.pop();
            long long b=a;
            if(!pq.empty()){
                b=pq.top();
                pq.pop();
            }
            if(a<k){
                ans++;
                pq.push(2*a +b);
            }

        }
        return ans;
    }
};