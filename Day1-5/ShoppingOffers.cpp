class Solution {
public:
    map<vector<int>, int> dp;
    
    int helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(dp.find(needs) != dp.end()) return dp[needs];
        
        int minCost = 0;
        for(int i = 0; i < needs.size(); i++) {
            minCost += needs[i] * price[i];
        }
        
        for(auto& offer : special) {
            vector<int> remainingNeeds = needs;
            bool canUseOffer = true;
            
            for(int i = 0; i < needs.size(); i++) {
                remainingNeeds[i] -= offer[i];
                if(remainingNeeds[i] < 0) {
                    canUseOffer = false;
                    break;
                }
            }
            
            if(canUseOffer) {
                int currentCost = offer.back() + helper(price, special, remainingNeeds);
                minCost = min(minCost, currentCost);
            }
        }
        
        return dp[needs] = minCost;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return helper(price, special, needs);
    }
};