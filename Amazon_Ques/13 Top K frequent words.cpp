class Solution
{
public:
    bool static compare(pair<string, int> a, pair<string, int> b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> ans;
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); i++)
        {
            m[words[i]]++;
        }

        vector<pair<string, int>> v;
        for (auto i : m)
        {
            v.push_back({i.first, i.second});
        }

        sort(v.begin(), v.end(), compare);
        int i = 0;
        while (k--)
        {
            ans.push_back(v[i].first);
            i++;
        }

        return ans;
    }
};