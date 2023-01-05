class Solution
{
public:
    double nthPersonGetsNthSeat(int n)
    {
        if (n == 1)
            return 1;
        return 0.5;
    }
};
// If a person is first he has probability 1 to get his own seat;
// in all other cases probability will be = 0.5 everytime,
// because he has only 2 options i.e , either his own seat is empty or his seat is occupied.