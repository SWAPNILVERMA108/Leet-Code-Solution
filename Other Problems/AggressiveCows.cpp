class Solution {
  public:
  
    bool canPlaceCows(vector<int> & arr,int k , int dist){
        int count =1;
        int lastPos = arr[0];
        
        for(int i=1;i<arr.size();i++){
            if(arr[i]-lastPos >=dist){
                count++;
                lastPos = arr[i];
            }
            if(count>= k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        
        int low = 1;
        int high = arr.back()-arr.front();
        int ans = 0 ;
         
         while(low<= high){
             int mid = low + (high-low)/2;
             
             if(canPlaceCows(arr, k,mid)){
                 ans = mid;
                 low = mid + 1;
                 
             }
             else{
                 high = mid-1;
             }
         }
         return ans;
        
    }
};