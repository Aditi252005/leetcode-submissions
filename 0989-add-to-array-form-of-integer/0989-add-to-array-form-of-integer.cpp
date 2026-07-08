class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        vector<int> ans;
        int carry=0;

        for(int i=n-1;i>=0;i--){
            int f= k%10;
            int sum=num[i]+f+carry;

            int add= sum%10;
            ans.push_back(add);

            sum=sum/10;
            if(sum) carry= sum%10;
            else carry=0;

            k=k/10;
        }

        while(k || carry){
            int f=k%10;
            int sum= f+carry;
            int add= sum%10;
            ans.push_back(add);

            sum=sum/10;
            if(sum) carry=sum%10;
            else carry=0;

            k=k/10;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};