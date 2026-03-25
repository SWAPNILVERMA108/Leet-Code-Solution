// class Solution {
// public:
//     int fib(int n) {
//         if(n == 0) return 0;
//         if(n == 1) return 1;

//         return fib(n - 1) + fib(n - 2);
//     }
// };


// optimal approch (O(n) complexity)

class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }
        int prev2 =0;
        int prev1 =1;
        for(int i=2;i<= n;i++){
            int curr = prev1 +prev2;
            prev2=prev1;
            prev1=curr;

            
        }
        return prev1;



    }
};