class Solution
{
    void solve(int k, int &n, vector<int> &vec, vector<vector<int>> &ans, int index, int sum)
    {
        if (sum == n && k == 0)
        {
            ans.push_back(vec);
            return;
        }
        if (sum > n || k == 0)
            return;

        for (int i = index; i <= 9; i++)
        {
            sum = sum + i;
            vec.push_back(i);
            solve(k - 1, n, vec, ans, i + 1, sum);
            vec.pop_back();
            sum = sum - i;
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> vec;
        int i = 1, sum = 0;
        solve(k, n, vec, ans, i, sum);
        return ans;
    }
};