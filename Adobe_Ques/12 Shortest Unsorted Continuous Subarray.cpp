class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int s = -1, e = -1, ph = n - 1, pl = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[pl])
                e = i;
            else
                pl = i;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > nums[ph])
                s = i;
            else
                ph = i;
        }
        if (s >= 0 && e >= 0)
            return (e - s + 1);
        else
            return 0;
    }
};

// The last index traversing from left which is smaller than element on its left
// Then traversing from right we find the last index which is greater than element on its right.
// MInimum Length = the distance betwen these two indices.