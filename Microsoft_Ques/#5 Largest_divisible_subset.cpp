class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size(), ans = -1, last = -1;
        vector<int> dp(n, 1);
        vector<int> trace(n, -1);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((nums[i] % nums[j] == 0) && (dp[j] >= dp[i]))
                {
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                }
            }
            if (dp[i] > ans)
            {
                ans = dp[i];
                last = i;
            }
        }
        vector<int> path;
        while (last != -1)
        {
            path.push_back(nums[last]);
            last = trace[last];
        }
        return path;
    }
};