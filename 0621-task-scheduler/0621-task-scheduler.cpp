class Solution {
public:
    int leastInterval(vector<char>& tasks, int m) {
        int n=tasks.size();

        priority_queue<int> pq;
        unordered_map<char,int> mp;
        for(auto it:tasks) mp[it]++;
        for(auto it:mp) pq.push(it.second);

        int count=0;
        queue<pair<int,int>> q;
        while(!pq.empty() || !q.empty()){
            count++;

            if(!q.empty() && q.front().first==count){
                pq.push(q.front().second);
                q.pop();
            }
            if(!pq.empty()){
                int f=pq.top();
                pq.pop();
                f--;

                if(f>0){
                    q.push({count+m+1,f});
                }
            }
        }

        return count;
    }
};