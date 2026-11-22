// class Solution {
// public:
//     bool checkString(string s) {

//     bool seenB = false;

//     for(int i=0;i<s.size();i++){
//         if(s[i]=='b'){
//             seenB=true;
//         }
//         else if(s[i]=='a' && seenB){
//             return false;
//         }
//     }

//     return true;

        
//     }
// };


class Solution {
public:
    bool checkString(string s) {
        return s.find("ba") == string::npos;
    }
};