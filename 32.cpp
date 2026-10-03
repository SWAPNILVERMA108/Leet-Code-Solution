class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {

                if (s[i - 1] == '(') {
                    dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
                }

                else {
                    int prev = dp[i - 1];

                    if (i - prev - 1 >= 0 &&
                        s[i - prev - 1] == '(') {

                        dp[i] = prev + 2;

                        if (i - prev - 2 >= 0) {
                            dp[i] += dp[i - prev - 2];
                        }
                    }
                }

                ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};