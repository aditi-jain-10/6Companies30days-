class Solution
{
public:
    double distance(pair<int, int> p1, pair<int, int> p2)
    {
        return (((p2.first - p1.first) * (p2.first - p1.first)) +
                ((p2.second - p1.second) * (p2.second - p1.second)));
    }

    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<pair<int, int>> pr(4);

        pr[0] = make_pair(p1[0], p1[1]);
        pr[1] = make_pair(p2[0], p2[1]);
        pr[2] = make_pair(p3[0], p3[1]);
        pr[3] = make_pair(p4[0], p4[1]);

        sort(pr.begin(), pr.end());

        if (distance(pr[0], pr[3]) == 2 * distance(pr[0], pr[1]) && distance(pr[0], pr[3]) == 2 * distance(pr[0], pr[2]) && distance(pr[0], pr[1]) == distance(pr[2], pr[3]) && distance(pr[0], pr[3]) != 0)
            return true;
        return false;
    }
};