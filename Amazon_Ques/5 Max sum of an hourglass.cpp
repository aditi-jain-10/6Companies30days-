class Solution
{
public:
    int maxSum(vector<vector<int>> &g)
    {
        int n = g.size(), m = g[0].size();
        long int sum = 0, maxi = 0;
        for (int i = 0; i <= n - 3; i++)
        {
            for (int j = 0; j <= m - 3; j++)
            {
                sum = g[i][j] + g[i][j + 1] + g[i][j + 2] + g[i + 1][j + 1] + g[i + 2][j] + g[i + 2][j + 1] + g[i + 2][j + 2];
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }
};