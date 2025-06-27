/*
 * Problem: Spiral Matrix
 * Approach: Layer-by-layer traversal using boundary markers
 * Time Complexity: O(m * n)
 * Space Complexity: O(1) additional (excluding output vector)
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        vector<int> res;

        while (top <= bottom && left <= right) {
            // Traverse from left to right along the top row
            for (int j = left; j <= right; j++)
                res.push_back(matrix[top][j]);
            top++;

            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            right--;

            // Traverse from right to left along the bottom row, if still within bounds
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    res.push_back(matrix[bottom][j]);
                bottom--;
            }

            // Traverse from bottom to top along the left column, if still within bounds
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }

        return res;
    }
};
