class Solution {
public:
    string getHint(string secret, string guess) {
        
        int n = secret.size();
        int m = guess.size();

        int Bulls = 0;
        int Cows = 0;

        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
                Bulls += 1;
            }

            else
            {
                mpp[secret[i]]++;
            }
        }

        for(int i=0;i<m;i++)
        {
            if (secret[i] != guess[i] && mpp[guess[i]] > 0)
            {
                Cows += 1;
                mpp[guess[i]]--;
            }
        }

        return to_string(Bulls) + "A" + to_string(Cows) + "B";


    }
};