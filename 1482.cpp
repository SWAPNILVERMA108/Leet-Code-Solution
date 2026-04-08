class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0, bouquet = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
                if (count == k) {
                    bouquet++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = (long long)m * k;
        if (need > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};