class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> m;
        int x = INT_MAX;
        for (int i = 0; i < cards.size(); i++)
        {
            if (m.find(cards[i]) == m.end())
            {
                m[cards[i]] = i;
            }
            else
            {
                x = min(x, i - m[cards[i]] + 1);
                m[cards[i]] = i;
            }
        }
        return x == INT_MAX ? -1 : x;
    }
};
