class Solution {
public:
    string removeKdigits(string num, int k) {

        // stack<char> st;
        string st = "";

        for(char c : num){
            while(k>0 && !st.empty() && st.back()>c){
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        //this next step is a safety step , agar meri string already increasing order mein hui
        //toh mera k kabhi bhi decrement nhi krega aur loop ke bad k is the same 
        //in the case of 12345 , koi remove nahi hua saaere stack ke ander chale gaye toh 
        //i will pop out k times so that number remains the smallest 
        while(k>0 && !st.empty()){
            st.pop_back();
            k--;
        }

        int idx=0;

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