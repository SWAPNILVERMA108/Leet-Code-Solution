//Time Complexity : O(n)

class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            if((i & 1) ==1){
                count++;

            }
        }
        return count;
        
    }
};



// Optimal Solution

// Time Complexity : O(1)

class Solution {
public:
    int countOdds(int low, int high) {

        return (high + 1)/2 - low/2;
        
    }
};