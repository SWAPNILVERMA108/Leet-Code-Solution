class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<int> dp(n, 1);
        vector<int> next(n, 0);

        for (int j = 1; j <= k; j++) {
            long long prefix = 0;

            for (int i = 1; i < n; i++) {

                prefix = (prefix + dp[i - 1]) % MOD;

                next[i] = (next[i - 1] + prefix) % MOD;
            }

            dp = next;
            fill(next.begin(), next.end(), 0);
        }

        return dp[n - 1];
    }
};