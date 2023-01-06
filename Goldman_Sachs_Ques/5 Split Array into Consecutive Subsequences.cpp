class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        int c = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if (m[x] && m[x + 1] && m[x + 2])
            {
                m[x]--;
                m[x + 1]--;
                m[x + 2]--;
                c -= 3;
                x += 3;
                while (m[x] > 0 && m[x] > m[x - 1])
                {
                    c--;

                    m[x]--;
                    x++;
                }
            }
        }
        return c == 0;
    }
};