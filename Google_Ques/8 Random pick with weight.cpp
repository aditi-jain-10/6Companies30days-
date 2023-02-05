vector<int> v;
Solution(vector<int> &w)
{
    v.push_back(w[0]);
    for (int i = 1; i < w.size(); i++)
        v.push_back(v[i - 1] + w[i]);
}

int pickIndex()
{
    int r = rand() % v.back();
    auto it = upper_bound(v.begin(), v.end(), r);
    return it - v.begin();
}