#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    int maxProduct(string s) {
        int n = s.size();
        int maxProduct = 0;

        for (int mask1 = 0; mask1 < (1 << n); ++mask1) {
            string sub1 = "";
            vector<bool> used(n, false);

            for (int i = 0; i < n; ++i) {
                if (mask1 & (1 << i)) {
                    sub1 += s[i];
                    used[i] = true;
                }
            }

            if (!isPalindrome(sub1)) continue;

            for (int mask2 = 0; mask2 < (1 << n); ++mask2) {
                string sub2 = "";

                for (int i = 0; i < n; ++i) {
                    if ((mask2 & (1 << i)) && !used[i]) {
                        sub2 += s[i];
                    }
                }

                if (isPalindrome(sub2)) {
                    int product = sub1.size() * sub2.size();
                    maxProduct = max(maxProduct, product);
                }
            }
        }

        return maxProduct;
    }
};
