class Solution {
public:
    void dfs(int node , vector<vector<int>> &forwardNbrs , vector<vector<int>> &backwardNbrs , int &ans , vector<int> &visited){
        visited[node] = 1;

        for(int nbr : forwardNbrs[node]){
            if(!visited[nbr]){
                ans = ans+1;
                dfs(nbr , forwardNbrs , backwardNbrs , ans , visited);
            }
        }

        for(int nbr : backwardNbrs[node]){
            if(!visited[nbr]){
                dfs(nbr , forwardNbrs , backwardNbrs , ans , visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forwardNbrs(n);
        vector<vector<int>> backwardNbrs(n);
        for(int i=0;i<connections.size();i++){
            int a = connections[i][0];
            int b = connections[i][1];
            forwardNbrs[a].push_back(b);
            backwardNbrs[b].push_back(a);
        }
            int ans = 0;
            vector<int> visited(n);
            dfs(0 , forwardNbrs , backwardNbrs , ans , visited);
            return ans;
    }
};