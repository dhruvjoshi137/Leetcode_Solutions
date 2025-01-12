class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(); // calculate the size of the array (prices)
        if (n == 0)
        {
            return 0; // this is the base case , if the size of the array is 0 , it will return 0
        }
        int max_profit = 0;  // for tracking the maximum profit
        int min = prices[0]; // we have kept the first element of the array assuming it is the smallest
        for (int i = 1; i < n; i++)
        {
            if (prices[i] < min)
            { // if the price of i is less than min then the min is updated to the same as prices[i]
                min = prices[i];
            }
            else
            {
                int profit = prices[i] - min; // calculate the profit made by subtracting min from prices[i]
                if (profit > max_profit)
                { // if the profit is greater than the max_profit then the max_profit is updated to the same as profit
                    max_profit = profit;
                }
            }
        }
        return max_profit; // print or return the max_profit , this will be the answer
    }
};

// note : this is a solution made to be run on the leetcode platform , it may not run in the code editors because no input has been given or asked for