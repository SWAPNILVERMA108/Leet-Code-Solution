class Solution {
public:
    
    struct Node {
        long long val;
        int l, r;

        bool operator<(const Node& other) const {
            return val < other.val;
        }
    };

    vector<vector<int>> stMax, stMin;
    vector<int> lg;

    int queryMax(int l, int r) {
        int j = lg[r - l + 1];
        return max(stMax[j][l], stMax[j][r - (1 << j) + 1]);
    }

    int queryMin(int l, int r) {
        int j = lg[r - l + 1];
        return min(stMin[j][l], stMin[j][r - (1 << j) + 1]);
    }

    long long getValue(int l, int r) {
        return 1LL * queryMax(l, r) - queryMin(l, r);
    }

    long long maxTotalValue(vector<int>& nums, int k) {

        int n = nums.size();

        // -------- Build Logs --------
        lg.resize(n + 1);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int K = lg[n] + 1;

        stMax.assign(K, vector<int>(n));
        stMin.assign(K, vector<int>(n));

        // level 0
        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        // build sparse table
        for (int j = 1; j < K; j++) {

            for (int i = 0; i + (1 << j) <= n; i++) {

                stMax[j][i] = max(
                    stMax[j - 1][i],
                    stMax[j - 1][i + (1 << (j - 1))]
                );

                stMin[j][i] = min(
                    stMin[j - 1][i],
                    stMin[j - 1][i + (1 << (j - 1))]
                );
            }
        }

        // -------- Max Heap --------
        priority_queue<Node> pq;

        // Push best subarray for each l
        for (int l = 0; l < n; l++) {

            long long val = getValue(l, n - 1);

            pq.push({val, l, n - 1});
        }

        long long ans = 0;

        // Take top k subarrays
        while (k--) {

            auto cur = pq.top();
            pq.pop();

            ans += cur.val;

            int l = cur.l;
            int r = cur.r;

            // move left in same sequence
            if (r - 1 >= l) {

                long long nxt = getValue(l, r - 1);

                pq.push({nxt, l, r - 1});
            }
        }

        return ans;
    }
};