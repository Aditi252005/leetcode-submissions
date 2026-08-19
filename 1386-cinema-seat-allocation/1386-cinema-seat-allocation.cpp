class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        int m=res.size();
        unordered_map<int,set<int>> mp;
        for(auto it:res) mp[it[0]].insert(it[1]);
        

        int count=2*(n-mp.size());
        for(auto it:mp){
            bool assign1=true,assign2=true,assign3=true;

            for(auto seat:it.second){
                if(seat>=2 && seat<=5) {assign1=false;}

                if(seat>=4 && seat<=7) {assign2=false;}

                if(seat>=6 && seat<=9) {assign3=false;}
            }

            if(assign1 && assign3) count+=2;
            else if((assign2 && assign3) || (assign1 && assign2)) count++;
            else if(assign1 || assign2 || assign3) count++;

        }

        return count;
    }
};