class Solution
{
public:
    vector<int> v1, v2, v3;
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        if (root)
        {
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        inorder(root1, v1);
        inorder(root2, v2);
        int i = 0, j = 0;
        int n = v1.size();
        int m = v2.size();
        while (i < n && j < m)
        {
            if (v1[i] <= v2[j])
            {
                v3.push_back(v1[i]);
                i++;
            }
            else
            {
                v3.push_back(v2[j]);
                j++;
            }
        }
        while (i < n)
        {
            v3.push_back(v1[i]);
            i++;
        }
        while (j < m)
        {
            v3.push_back(v2[j]);
            j++;
        }
        return v3;
    }
};