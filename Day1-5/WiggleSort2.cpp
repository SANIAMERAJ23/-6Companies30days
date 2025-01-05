#include<bits/stdc++.h>
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        int n = nums.size();
        int j = n - 1;
        int i = 1;
        
        while(i < n) {
            nums[i] = sorted[j];
            j--;
            i += 2;
        }
        
        i = 0;
        while(i < n) {
            nums[i] = sorted[j];
            j--;
            i += 2;
        }
    }
};