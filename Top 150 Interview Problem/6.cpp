class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = true;

        for (char c : s) {
            rows[currRow] += c;

            if (currRow == 0) {
                goingDown = true;
            } else if (currRow == numRows - 1) {
                goingDown = false;
            }

            currRow += goingDown ? 1 : -1;
        }

        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};