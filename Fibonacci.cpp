class Solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        int a = 0; // 0th fibonacci no
        int b = 1; // 1st fibonacci no

        int i = 2;
        while (i <= n)
        {
            int c = a + b;
            a = b;
            b = c;
            i = i + 1;
        }
        return b;
    }
};