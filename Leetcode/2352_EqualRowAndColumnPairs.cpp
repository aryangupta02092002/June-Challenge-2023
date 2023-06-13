class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> freq;
        int row = grid.size(), col = grid[0].size(), ans = 0;

        for (vector<int> row : grid) {
            freq[row] += 1;
        }

        for (int i = 0; i < row; i++) {
            vector<int> column = {};
            for (int j = 0; j < col; j++) {
                column.push_back(grid[j][i]);
            }
            ans += freq[column];
        }
        return ans;
    }
};
