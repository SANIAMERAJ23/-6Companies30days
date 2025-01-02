class Solution {
    vector<vector<int>> rects;
    vector<int> cumulativeSum;
    int totalPoints;

public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        totalPoints = 0;

        for (auto& rect : rects) {
            int points = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            totalPoints += points;
            cumulativeSum.push_back(totalPoints);
        }
    }

    vector<int> pick() {
        int randPoint = rand() % totalPoints + 1; 
        int rectIndex = lower_bound(cumulativeSum.begin(), cumulativeSum.end(), randPoint) - cumulativeSum.begin();

        auto& rect = rects[rectIndex];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);

        return {x, y};
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */