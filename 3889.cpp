class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq(128, 0);
        for (char c : s) freq[c]++;

        int ans = 0;
        vector<bool> vis(128, false);

        for (char c : s) {
            if (vis[c]) continue;

            char m;
            if (islower(c)) m = 'z' - (c - 'a');
            else if (isdigit(c)) m = '9' - (c - '0');
            else continue;

            ans += abs(freq[c] - freq[m]);
            vis[c] = true;
            vis[m] = true;
        }

        return ans;
    }
};