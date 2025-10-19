class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        long long a = 1;
        long long b = 1;
        long long i = 2;
        while (i <= n)
        {
            long long temp = a + b;
            a = b;
            b = temp;
            i = i + 1;
        }
        return b;
    }
};