class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int m) {
        int n=tasks.size();

        unordered_map<int,long long> mp;
        long long count=0;
        for(int i=0;i<n;i++){
            count++;
            if(count<mp[tasks[i]]){
                count+=mp[tasks[i]]-count;
            }
            mp[tasks[i]]=count+m+1;
        }

        return count;
    }
};