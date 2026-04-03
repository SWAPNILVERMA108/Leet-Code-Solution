// Koko Eating Bananas (Optmal Solution using Binary Search)

class Solution {

public:
    int findHours(vector<int>& piles, int k) {
        int total = 0;
        for (int p : piles) {
            total += (p + k - 1) / k;
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (findHours(piles, mid) <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};