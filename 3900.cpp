class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int first1 = -1, last1 = -1;
        int first0 = -1, last0 = -1;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (first1 == -1)
                    first1 = i;
                last1 = i;
            } else {
                if (first0 == -1)
                    first0 = i;
                last0 = i;
            }
        }

        vector<int> pos(2 * n + 1, -1);
        vector<int> pos1(2 * n + 1, -1);
        vector<int> pos0(2 * n + 1, -1);

        int N = n;
        pos[N] = 0;

        int val = 0;
        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            val += (s[i - 1] == '1' ? 1 : -1);

            if (pos[val + N] != -1) {
                ans = max(ans, i - pos[val + N]);
            }

            if (first1 != -1) {
                int target = val + 2;
                if (target + N >= 0 && target + N <= 2 * N) {
                    if (i <= last1) {
                        if (pos[target + N] != -1) {
                            ans = max(ans, i - pos[target + N]);
                        }
                    } else {
                        if (pos1[target + N] != -1) {
                            ans = max(ans, i - pos1[target + N]);
                        }
                    }
                }
            }

            if (first0 != -1) {
                int target = val - 2;
                if (target + N >= 0 && target + N <= 2 * N) {
                    if (i <= last0) {
                        if (pos[target + N] != -1) {
                            ans = max(ans, i - pos[target + N]);
                        }
                    } else {
                        if (pos0[target + N] != -1) {
                            ans = max(ans, i - pos0[target + N]);
                        }
                    }
                }
            }

            if (pos[val + N] == -1)
                pos[val + N] = i;
            if (first1 != -1 && i > first1 && pos1[val + N] == -1)
                pos1[val + N] = i;
            if (first0 != -1 && i > first0 && pos0[val + N] == -1)
                pos0[val + N] = i;
        }

        return ans;
    }
};