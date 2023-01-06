class Solution
{
public:
    int trailingZeroes(int n)
    {
        if (n < 0)
            return -1;
        int p = 5, c = 0;
        while (n / p > 0)
        {
            c += n / p;
            p *= 5;
        }
        return c;
    }
};

// We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s.
// So if we count 5s in prime factors, we are done. How to count the total number of 5s in prime factors of n!?
// A simple way is to calculate floor(n/5). For example, 7! has one 5, 10! has two 5s.
// It is not done yet, there is one more thing to consider. Numbers like 25, 125, etc have more than one 5.
// For example, if we consider 28! we get one extra 5 and the number of 0s becomes 6.
// Handling this is simple, first, divide n by 5 and remove all single 5s, then divide by 25 to remove extra 5s, and so on.