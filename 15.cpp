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




// this solution is for leetcode submission and is the most efficient one among the three solutions provided above.
// time complexity: O(n^2) because of the two nested loops and the two-pointer technique
// space complexity: O(1) because we are not using any extra space to store the triplets,
//we are directly adding them to the answer vector. 

    
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);

                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1]) j++;   
                    while(j < k && nums[k] == nums[k+1]) k--;  
                }
            }
        }

        return ans;
    }
};