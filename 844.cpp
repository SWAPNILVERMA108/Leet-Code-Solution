class Solution {
public:

    string first(string s){
        string st;
        for(char ch : s){
            if(ch=='#'){
                if(!st.empty()){
                    st.pop_back();
                }
                
            }
            else{
                    st.push_back(ch);
                }
        }
        return st;
    }

    string second(string t){
        string ts;
        for(char ch : t){
            if(ch=='#'){
                if(!ts.empty()){
                    ts.pop_back();
                }
                
            }
            else{
                    ts.push_back(ch);
                }
        }
        return ts;
    }
    bool backspaceCompare(string s, string t) {
        return first(s)==second(t);
        
        
    }
};


// Optimal Approch : using two pointer

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int skipS = 0;
        int skipT = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS) {
                    skipS--;
                    i--;

                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT) {
                    skipT--;
                    j--;

                } else {
                    break;
                }
            }

            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};