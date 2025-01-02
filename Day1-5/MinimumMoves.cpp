class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        
        int median = nums[n / 2];

        for(int i=0;i<n;i++)
        {
            int diff = abs(nums[i]-median);
            res += diff;
        }

        return res;
    }
};