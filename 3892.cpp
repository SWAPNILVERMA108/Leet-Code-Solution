class Solution {
public:
    long long solveDP(const vector<long long>& cost, int start, int end,
                      int k) {
        if (k == 0)
            return 0;
        if (end - start + 1 < k * 2 - 1)
            return 1e18;

        vector<long long> prev2(k + 1, 1e18);
        vector<long long> prev1(k + 1, 1e18);
        prev2[0] = 0;
        prev1[0] = 0;

        for (int i = start; i <= end; ++i) {
            vector<long long> curr(k + 1, 1e18);
            curr[0] = 0;

            for (int j = 1; j <= k; ++j) {
                long long pick = prev2[j - 1] + cost[i];
                long long skip = prev1[j];
                curr[j] = min(pick, skip);
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1[k];
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        if (k > n / 2)
            return -1;
        if (k == 0)
            return 0;

        vector<long long> cost(n);
        for (int i = 0; i < n; i++) {
            int leftNeighbor = nums[(i - 1 + n) % n];
            int rightNeighbor = nums[(i + 1) % n];
            long long target = max(leftNeighbor, rightNeighbor) + 1LL;
            cost[i] = max(0LL, target - nums[i]);
        }

        long long ans1 = solveDP(cost, 1, n - 1, k);
        long long ans2 = cost[0] + solveDP(cost, 2, n - 2, k - 1);
        long long finalAns = min(ans1, ans2);

        if (finalAns >= 1e18)
            return -1;

        return static_cast<int>(finalAns);
    }
};