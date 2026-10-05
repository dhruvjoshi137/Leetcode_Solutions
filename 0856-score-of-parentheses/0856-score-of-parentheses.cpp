class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(char ch : s){
            if(ch == '('){
                st.push(0);
            }else if(ch == ')'){
                int ans = st.top();
                st.pop();

                int res = 0;
                if(ans==0){
                    res = 1;
                }else{
                    res = 2*ans;
                }
                st.top() += res;
            }
        }
        return st.top();
    }
};