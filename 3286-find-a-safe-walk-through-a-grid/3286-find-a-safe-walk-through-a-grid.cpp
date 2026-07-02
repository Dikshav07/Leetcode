class Solution {
public:
    vector<vector<int>> dic = {{0,1},{1,0},{-1,0},{0,-1}};

    bool solve(vector<vector<int>>& grid, int health, int m, int n,
               vector<vector<int>>& visited, int x, int y,
               vector<vector<vector<int>>>& dp) {

        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;

        health -= grid[x][y];

        if (health <= 0)
            return false;

        if (visited[x][y])
            return false;

        if (dp[x][y][health] != -1)
            return dp[x][y][health];

        if (x == m - 1 && y == n - 1)
            return dp[x][y][health] = true;

        visited[x][y] = 1;

        for (int i = 0; i < dic.size(); i++) {
            int newX = x + dic[i][0];
            int newY = y + dic[i][1];

            if (solve(grid, health, m, n, visited, newX, newY, dp))
                return dp[x][y][health] = true;
        }

        visited[x][y] = 0;

        return dp[x][y][health] = false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m + 1, vector<int>(n + 1, 0));

        vector<vector<vector<int>>> dp(
            m + 1,
            vector<vector<int>>(n + 1, vector<int>(health + 1, -1))
        );

        return solve(grid, health, m, n, visited, 0, 0, dp);
    }
};