class Solution
{
public:
    bool cycle(int node, vector<vector<int>> &pre, vector<int> &vis, vector<int> &dfsvis)
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        for (auto it : pre[node])
        {
            if (!vis[it])
            {
                if (cycle(it, pre, vis, dfsvis))
                    return true;
            }
            else if (dfsvis[it])
            {
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &pre)
    {
        int n = pre.size();
        vector<int> vis(numCourses, 0), dfsvis(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto it : pre)
        {
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (cycle(i, adj, vis, dfsvis))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
