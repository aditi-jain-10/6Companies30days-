class Solution
{
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 0)
            return;
        grid[i][j] = -1;
        dfs(i - 1, j, n, m, grid);
        dfs(i + 1, j, n, m, grid);
        dfs(i, j - 1, n, m, grid);
        dfs(i, j + 1, n, m, grid);
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int c = 0;
        if (m == 0 || n == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                    dfs(i, j, n, m, grid);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    dfs(i, j, n, m, grid);
                    c++;
                }
            }
        }
        return c;
    }
};
