class Solution {
  public:
  
    bool dfs(int node , vector<int> adj[], vector<int>& visited , int parent){
        visited[node] = 1;
        for(int nbr : adj[node]){
            if(!visited[nbr]){
                int ans = dfs(nbr , adj , visited , node);
                if(ans == true) return true;
            }else if(visited[nbr] && parent != nbr){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); //because the graph is undirected
        }
        vector<int> visited(V);
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                bool ans = dfs(i , adj , visited , -1);
                if(ans == true){
                    return true;
                }
            }
        }
        return false;
    }
};