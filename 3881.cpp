class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();

        if (n < 3)
            return 0;

        if (n % 2 == 1) {
            long long ans = 0;

            for (int i = 1; i < n - 1; i += 2) {
                int leftNeighbor = nums[i - 1];
                int rightNeighbor = nums[i + 1];
                long long target = max(leftNeighbor, rightNeighbor) + 1LL;

                if (nums[i] < target) {
                    ans += (target - nums[i]);
                }
            }
            return ans;
        } else {
            long long currentEvenCost = 0;
            for (int i = 2; i < n - 1; i += 2) {
                int leftNeighbor = nums[i - 1];
                int rightNeighbor = nums[i + 1];
                long long target = max(leftNeighbor, rightNeighbor) + 1LL;

                if (nums[i] < target) {
                    currentEvenCost += (target - nums[i]);
                }
            }

            long long bestAns = currentEvenCost;
            long long currentOddCost = 0;

            for (int i = 1; i < n - 2; i += 2) {
                int left1 = nums[i - 1];
                int right1 = nums[i + 1];
                long long target1 = max(left1, right1) + 1LL;
                if (nums[i] < target1) {
                    currentOddCost += (target1 - nums[i]);
                }

                int evenIndex = i + 1;
                int left2 = nums[evenIndex - 1];
                int right2 = nums[evenIndex + 1];
                long long target2 = max(left2, right2) + 1LL;
                if (nums[evenIndex] < target2) {
                    currentEvenCost -= (target2 - nums[evenIndex]);
                }

                bestAns = min(bestAns, currentOddCost + currentEvenCost);
            }

            return bestAns;
        }
    }
};