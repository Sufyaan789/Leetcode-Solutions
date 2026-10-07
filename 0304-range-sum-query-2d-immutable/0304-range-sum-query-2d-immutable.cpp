class NumMatrix {
public:
    vector<vector<int>> m;

    NumMatrix(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Row prefix sum
        for (int i = 0; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        // Column prefix sum
        for (int j = 0; j < cols; j++) {
            for (int i = 1; i < rows; i++) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }

        m = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        int r = 0, s = 0, t = 0;

        if (col1 - 1 >= 0) {
            r = m[row2][col1 - 1];
        }

        if (row1 - 1 >= 0) {
            s = m[row1 - 1][col2];
        }

        if (row1 - 1 >= 0 && col1 - 1 >= 0) {
            t = m[row1 - 1][col1 - 1];
        }

        return m[row2][col2] - r - s + t;
    }
};
