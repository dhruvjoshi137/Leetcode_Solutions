class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;

        for(const string& word : words){
            int weight = 0;

            for(char character : word){
                int AlpInd = character - 'a';
                weight += weights[AlpInd];
            }

            int ModuloResult = weight % 26;

            char MC = 'z' - ModuloResult;

            res.push_back(MC);
        }
        return res;
    }
};