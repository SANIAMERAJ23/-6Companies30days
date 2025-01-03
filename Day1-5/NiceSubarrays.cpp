class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int res = 0;
        map<int,int> mpp;

        int odd = 0;
        mpp[0] = 1;
        for(auto i : nums)
        {
           odd += i%2;

           if(mpp.find(odd-k)!=mpp.end())
           {
             res+=mpp[odd-k];
           }

           mpp[odd]++;
        }

        return res;
    }
};