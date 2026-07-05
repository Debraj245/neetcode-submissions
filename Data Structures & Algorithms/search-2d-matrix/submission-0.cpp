class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int startRow = 0, endRow = m - 1;

        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            if (target >= mat[midRow][0] && target <= mat[midRow][n - 1]) {

                int startCol = 0, endCol = n - 1;

                while (startCol <= endCol) {
                    int midCol = startCol + (endCol - startCol) / 2;

                    if (mat[midRow][midCol] == target)
                        return true;
                    else if (target > mat[midRow][midCol])
                        startCol = midCol + 1;
                    else
                        endCol = midCol - 1;
                }

                return false;
            }
            else if (target > mat[midRow][n - 1]) {
                startRow = midRow + 1;
            }
            else {
                endRow = midRow - 1;
            }
        }

        return false;
    }
};