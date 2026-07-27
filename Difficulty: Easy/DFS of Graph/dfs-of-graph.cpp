class Solution {
  private:
    // Helper function renamed to avoid shadowing the public dfs() function
    void dfsHelper(int node, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& ls) {
        vis[node] = 1;
        ls.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfsHelper(neighbor, adj, vis, ls);
            }
        }
    }

  public:
    // This matches what Driver.cpp is calling: obj.dfs(adj)
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        vector<int> ls;
        
        dfsHelper(0, adj, vis, ls);
        
        return ls;
    }
};