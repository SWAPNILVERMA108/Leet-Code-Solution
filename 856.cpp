// Approch 1 

//class Solution {
// public:
//     int scoreOfParentheses(string s) {
//         int n = s.length();

//         vector<int> vec;
//         int score = 0;

//         for(int i=0;i<n;i++){
//             if(s[i]=='('){
//                 vec.push_back(score);
//                 score = 0;
//             }else{
//                 if(s[i-1]=='('){
//                     score = vec.back() + 1;

//                 }else{
//                     score = vec.back()+ (2*score);
//                 }
//                 vec.pop_back();
//             }
//         }

//         return score;


        
//     }
// };


// Approch 2 

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int score = 0;
        int depth = 0;

        for(int i=0;i<n;i++){

            if(s[i]=='('){
                depth++;
            }else{
                depth --;

                if(s[i-1]=='('){
                    score += (1<<depth);
                }
            }

        }
        return score;
        
    }
};