class Solution
{
public:
    void ans(vector<vector<int>> &grid, int i, int j, int &n)
    {
        if (grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        n++;
        if (i > 0)
            ans(grid, i - 1, j, n);
        if (j > 0)
            ans(grid, i, j - 1, n);
        if (i + 1 < grid.size())
            ans(grid, i + 1, j, n);
        if (j + 1 < grid[0].size())
            ans(grid, i, j + 1, n);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = 0;
        int n = 1;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    n = 0;
                    ans(grid, i, j, n);
                    m = max(m, n);
                }
            }
        }
        return m;
    }
};