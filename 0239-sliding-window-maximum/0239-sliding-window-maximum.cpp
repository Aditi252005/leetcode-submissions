class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;

        vector<int> ans;
        int j=0;
        while(j<k-1) {pq.push({nums[j],j});j++;}
        while(j<n){
            pq.push({nums[j],j});

            while(pq.top().second<j-k+1) pq.pop();
            ans.push_back(pq.top().first);

            j++;
        }
        return ans;
    }
};