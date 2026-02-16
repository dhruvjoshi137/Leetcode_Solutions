class Solution {
public:
    bool isBalanced(string str) {
        stack<char> s;
    for(char ch: str){
        switch(ch){
            case '(': 
            case '{': 
            case '[': s.push(ch); break;
            case ')': if(!s.empty() and s.top()=='(') s.pop(); else return false; break;
            case '}': if(!s.empty() and s.top()=='{') s.pop(); else return false; break;
            case ']': if(!s.empty() and s.top()=='[') s.pop(); else return false; break;
        }
    }
    return s.empty();
}

    bool isValid(string s){
        return isBalanced(s);
    }
};