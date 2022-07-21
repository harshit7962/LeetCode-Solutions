class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        numRows = grid.size();
        numCols = grid[0].size();
        
        vector<int> result(numCols, -1);
        for (int col = 0; col < numCols; col++) {
            result[col] = findFinalCol(grid, col);
        }
        return result;
    }
    
    int findFinalCol(const vector<vector<int>>& grid, const int startCol) {
        int col = startCol;
        for (int row = 0; row < numRows; row++) {
            col = getNextCol(grid, row, col);
            if (col == STUCK) return STUCK;
        }
        return col;
    }
    
    int getNextCol(const vector<vector<int>>& grid, const int row, const int col) {
        if (getBoardDirection(grid, row, col) == SLOPE_DOWN) {
            if (getBoardDirection(grid, row, col + 1) == SLOPE_UP) return STUCK;
            return col + 1;
        } else {
            if (getBoardDirection(grid, row, col - 1) == SLOPE_DOWN) return STUCK;
            return col - 1;
        }
    }
    
    int getBoardDirection(const vector<vector<int>>& grid, const int row, const int col) {
        if (col < 0) return SLOPE_DOWN;
        if (col >= numCols) return SLOPE_UP;
        return grid[row][col];
    }
    
    const int SLOPE_DOWN = 1;
    const int SLOPE_UP = -1;
    const int STUCK = -1;
    int numRows = 0;
    int numCols = 0;
};