class Solution
{
public:
    double distance(vector<int> &a, vector<int> &b)
    {
        // return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<double, int> m;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    m[distance(points[i], points[j])]++;
                }
            }
            for (auto it : m)
            {
                if (it.second > 1)
                    ans += it.second * (it.second - 1);
            }
        }
        return ans;
    }
};
