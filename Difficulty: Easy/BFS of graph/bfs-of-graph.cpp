
class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        // Use a vector for visited to handle dynamic sizing safely
        vector<int> vis(n, 0);
        vector<int> result; // Renamed from 'bfs' to 'result'
        
        queue<int> q;

        // Starting from node 0
        vis[0] = 1;
        q.push(0);
        
        while(!q.empty()){
             int node = q.front();
             q.pop();
             result.push_back(node);
             
             for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
             }
        }
        return result;
    }
};