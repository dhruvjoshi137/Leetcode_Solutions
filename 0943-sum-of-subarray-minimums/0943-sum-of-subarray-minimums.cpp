class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st; // to store the indexes (note that)

        // now traverse the loop
        for (int i = 0; i < n; i++) {
            // now first check whether the stack is empty
            if (st.empty()) {
                res[i] =
                    -1; // means we didnt get min ele in left of that curr ele
            } else {
                // if stack is not empty
                while (!st.empty() &&
                       arr[st.top()] >= arr[i]) { // >= to handle duplicate ele
                    // and the stack top is greater than arr[i]
                    st.pop();
                }
                // and update res
                res[i] = st.empty() ? -1 : st.top();
            }

            // push the index in stack
            st.push(i);
        }
        return res;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;

        // for right we have to start from last
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                res[i] =
                    n; // means we have not got min ele in right of curr ele
            } else {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    st.pop();
                }
                // after pop and cond
                res[i] = st.empty()
                             ? n
                             : st.top(); // as now st.top() is contain index
                                         // which have value less than currr ele
            }
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = getNSL(arr, n); // next smaller ele in left
        vector<int> NSR = getNSR(arr, n); // next smaller ele in right

        long long sum = 0;
        int M = 1e9 + 7;

        // now we have to traverse on both NSL and NSR
        // cal how many ele may be there in left and right
        for (int i = 0; i < n; i++) {
            long long leftside = i - NSL[i];  // how many ele are there in left
            long long rightside = NSR[i] - i; // how many ele are there in right

            // now we have suppose m in left and n in right then total number of
            // subarr can be m*n
            long long totoalSubArrWays = leftside * rightside;

            // and then if we have to calculate the actual value of that arr[i]
            // then
            long long totalSum = totoalSubArrWays * arr[i];

            // and then add all sum as we want the sum of min sum from all
            // subarr
            sum = (sum + totalSum) % M;
        }
        return sum;
    }
};