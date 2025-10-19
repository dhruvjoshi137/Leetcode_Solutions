class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";

        for(char c : num){
            while(k>0 && !st.empty() && st.back()>c){
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
            while(k>0 && !st.empty()){
                st.pop_back();
                k--;
            }

            int idx = 0;
            while(idx<st.size() && st[idx]=='0'){
                idx++;
            }

            string res = st.substr(idx);
            if(res.empty()){
                return "0";
            }else{
                return res;
            }
        
    }
};