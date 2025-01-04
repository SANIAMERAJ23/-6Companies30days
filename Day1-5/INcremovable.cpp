class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int check = 1;
                int last = -1;

                for(int k=0;k<n;k++)
                {
                    if(k>=i && k<=j)
                     continue;

                    if(last>=nums[k])
                    {
                        check = 0;
                        break;
                    }

                    last = nums[k];
                }

                if(check)
                {
                   cnt++;
                }

            }
        }

        return cnt;
    }
};