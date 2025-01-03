class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> ans;
        unordered_map<string,int> mpp;

        int n = s.size();
        for(int i=0;i<=n-10;i++)
        {
            string sub = s.substr(i,10);
            mpp[sub]++;

            if(mpp[sub]==2)
             ans.push_back(sub);
        }

        return ans;
    }
};