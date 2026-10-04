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