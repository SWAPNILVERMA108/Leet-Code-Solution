int cnt = 0;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

    while (left <= mid)
        temp.push_back(arr[left++]);

    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void countPair(vector<int> &arr,int low , int mid,int high){
    int right = mid + 1;

    for(int i = low; i <= mid; i++){
        while(right <= high && arr[i] > 2LL * arr[right]){
            right++;
        }
        cnt += (right - (mid + 1));
    }
}

void mergeSortHelper(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    mergeSortHelper(arr, low, mid);
    mergeSortHelper(arr, mid + 1, high);

    countPair(arr, low, mid, high);

    merge(arr, low, mid, high);
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        cnt = 0;
        mergeSortHelper(nums, 0, nums.size() - 1);
        return cnt;
    }
    
};