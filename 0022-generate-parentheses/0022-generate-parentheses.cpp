class Solution {
public:
    /**
     * Generates all combinations of well-formed parentheses for a given number of pairs.
     * 
     * @param pairCount Number of pairs of parentheses.
     * @return A vector containing all valid combinations.
     */
    vector<string> generateParenthesis(int pairCount) {
        vector<string> results;
        buildParenthesis(pairCount, pairCount, "", results);
        return results;
    }

    /**
     * Recursively builds valid parentheses combinations.
     * 
     * @param openRemaining Number of opening parentheses left to use.
     * @param closeRemaining Number of closing parentheses left to use.
     * @param current The current state of the string being built.
     * @param results Reference to the result vector storing valid combinations.
     */
    void buildParenthesis(int openRemaining, int closeRemaining, string current, vector<string>& results) {
        if (closeRemaining == 0&&openRemaining==0) {
            results.push_back(current);
        }

        if (openRemaining > 0) {
            buildParenthesis(openRemaining - 1, closeRemaining, current + "(", results);
        }

        if (closeRemaining > openRemaining) {
            buildParenthesis(openRemaining, closeRemaining - 1, current + ")", results);
        }
    }
};
