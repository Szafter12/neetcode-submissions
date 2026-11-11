class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;

        int islands {0};

        for (size_t i{0}; i < grid.size(); i++) {
            for (size_t j{0}; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != '1') return;

        grid[r][c] = '#';

        dfs(grid,r, c-1);
        dfs(grid,r-1, c);
        dfs(grid,r, c+1);
        dfs(grid,r+1, c);
    }
};
