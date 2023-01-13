class Solution
{
public:
    string fractionToDecimal(int num, int den)
    {
        if (num == 0)
            return "0";
        string ans = "";
        if ((num < 0 && den > 0) || (num > 0 && den < 0))
            ans += "-";
        long long int n = labs(num), d = labs(den);
        long long int q = n / d;
        long long int r = n % d;
        ans += to_string(q);
        if (r == 0)
            return ans;
        ans += ".";
        unordered_map<long long, int> mp;
        while (r != 0)
        {
            if (mp.find(r) != mp.end())
            {
                int pos = mp[r];
                ans.insert(pos, "(");
                ans += ")";
                break;
            }
            else
            {
                mp[r] = ans.length();
                r = r * 10;
                q = r / d;
                r = r % d;
                ans += to_string(q);
            }
        }
        return ans;
    }
};
