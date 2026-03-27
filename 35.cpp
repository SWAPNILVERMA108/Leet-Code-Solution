//problem no 35 : Search insert position (optimal solution)


class Solution {
public:
    int insertElement(vector<int> nums, int st, int end, int target) {
        if (st > end) {
            return st;
        }

        int mid = st + (end - st) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return insertElement(nums, st, mid - 1, target);
        } else {
            return insertElement(nums, mid + 1, end, target);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        return insertElement(nums, 0, nums.size() - 1, target);
    }
};