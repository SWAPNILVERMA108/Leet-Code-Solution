// Not for leetcode submission, just for practice and understanding the problem better. The second solution is more efficient than the first one.
// time complexity: O(n^3 log n) because of the three nested loops and sorting each triplet
// space complexity: O(n) because of the set storing unique triplets


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {

                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                }
            }
        }

        for (auto it : st) {
            ans.push_back(it);
        }

        return ans;
    }
};



// also this solution is not for leetcode submission, just for practice and understanding the problem better. The third solution is more efficient than both the first and second ones.
// time complexity: O(n^2 log n) because of the two nested loops and sorting each triplet
// space complexity: O(n) because of the set storing unique triplets

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;

        for(int i = 0; i < n; i++) {
            set<int> hashset;

            for(int j = i + 1; j < n; j++) {

                int third = -(nums[i] + nums[j]);   // fixed line

                if(hashset.find(third) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

                hashset.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};