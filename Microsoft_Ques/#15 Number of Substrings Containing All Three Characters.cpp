class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int count = 0, inda = -1, indb = -1, indc = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
                inda = i;
            else if (s[i] == 'b')
                indb = i;
            else
                indc = i;
            if (i > 1)
            {
                count += min({inda, indb, indc}) + 1;
            }
        }
        return count;
    }
};