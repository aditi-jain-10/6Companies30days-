class Solution
{
public:
    int rev(int n)
    {
        int r = 0;
        while (n > 0)
        {
            r = r * 10 + n % 10;
            n /= 10;
        }
        return r;
    }
    int countNicePairs(vector<int> &nums)
    {
        int mod = 1e9 + 7;
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i] - rev(nums[i])]++;
        }
        int ans = 0;
        for (auto x : mp)
        {
            long long cnt = x.second;
            cnt *= (cnt - 1);
            cnt /= 2;
            ans += cnt % mod;
        }
        return ans % mod;
    }
};