class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        long long n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        vector<long long> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            dp[0] += i * nums[i];
        }
        int j = n - 1;
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + (sum - (n * nums[j]));
            j--;
        }
        return *max_element(dp.begin(), dp.end());
    }
    // sum=a+b+c+d+e
    // f(0)=0a+1b+2c+3d+4e
    // f(1)=0e+1a+2b+3c+4d
    // f(1)-f(0)=1a+1b+1c+1d-4e  +e-e
    // f(1)-f(0)= sum-5e
};