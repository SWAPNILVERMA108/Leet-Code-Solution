class Solution {
    struct Node {
        int count;
        int gcd_val;
    };
    
    vector<Node> tree;

    void build(int node, int start, int end, const vector<int>& nums, int p) {
        if (start == end) {
            if (nums[start] % p == 0) {
                tree[node].count = 1;
                tree[node].gcd_val = nums[start];
            } else {
                tree[node].count = 0;
                tree[node].gcd_val = 0;
            }
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums, p);
        build(2 * node + 1, mid + 1, end, nums, p);
        tree[node].count = tree[2 * node].count + tree[2 * node + 1].count;
        tree[node].gcd_val = std::gcd(tree[2 * node].gcd_val, tree[2 * node + 1].gcd_val);
    }

    void update(int node, int start, int end, int idx, int val, int p) {
        if (start == end) {
            if (val % p == 0) {
                tree[node].count = 1;
                tree[node].gcd_val = val;
            } else {
                tree[node].count = 0;
                tree[node].gcd_val = 0;
            }
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val, p);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val, p);
        }
        tree[node].count = tree[2 * node].count + tree[2 * node + 1].count;
        tree[node].gcd_val = std::gcd(tree[2 * node].gcd_val, tree[2 * node + 1].gcd_val);
    }

public:
    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
        int n = nums.size();
        tree.resize(4 * n + 1);
        build(1, 0, n - 1, nums, p);
        
        int ans = 0;
        for (const auto& q : queries) {
            int ind = q[0];
            int val = q[1];
            nums[ind] = val;
            update(1, 0, n - 1, ind, val, p);
            
            if (tree[1].gcd_val == p) {
                if (tree[1].count < n) {
                    ans++;
                } else {
                    if (n > 10) {
                        ans++;
                    } else {
                        bool found = false;
                        for (int i = 0; i < n; i++) {
                            int cur_gcd = 0;
                            for (int j = 0; j < n; j++) {
                                if (i != j) {
                                    cur_gcd = std::gcd(cur_gcd, nums[j]);
                                }
                            }
                            if (cur_gcd == p) {
                                found = true;
                                break;
                            }
                        }
                        if (found) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};