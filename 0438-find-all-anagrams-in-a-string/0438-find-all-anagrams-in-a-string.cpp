class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp;
        for(char ch : p){
            mp[ch]++;
        }

        int i=0 , j = 0;
        vector<int> ans; //final resultant vector which will contain the starting indeices of all the anagrams 
        int n = s.length(); //string size
        int k = p.length(); //window size
        int count = mp.size();

        while(j<n){
            if(mp.find(s[j]) !=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }

            if(j-i+1 < k){
                j++;
            }

            else if(j-i+1 == k){
                if(count==0){
                    ans.push_back(i);
                }

                if(mp.find(s[i]) != mp.end()){
                    if(mp[s[i]]==0){
                        count++;
                    }
                    mp[s[i]]++;
                }

                i++;
                j++;
            }

        }

        return ans;
    }
};