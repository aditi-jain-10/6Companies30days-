class Solution
{
public:
    int solve(string &a, string b)
    {
        int i = 0, j = 0;
        int n = a.length(), m = b.length();
        while (i < n && j < m)
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        return (j == m);
    }

    int numMatchingSubseq(string s, vector<string> &words)
    {
        unordered_map<string, int> m;
        int c = 0;
        for (int i = 0; i < words.size(); i++)
        {
            m[words[i]]++;
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (solve(s, it->first))
                c += it->second;
        }
        return c;
    }
};
