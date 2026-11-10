class Solution {
public:
    void findCombination(int start, int target, vector<int>& candidate,
                         vector<int>& current, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidate.size(); i++) {
            if (candidate[i] > target)
                break;

            current.push_back(candidate[i]);

            findCombination(i, target - candidate[i], candidate, current,
                            result);

            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        findCombination(0, target, candidates, current, result);

        return result;
    }
};