class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> graph;
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> visited = bfs(graph , source , n);
        if(visited[destination] == 0){
            return false;
        }else{
            return true;
        }
    }

    vector<int> bfs(unordered_map<int , vector<int>> graph , int source , int n ){
        queue<int> q;
        vector<int> visited(n , 0);
        visited[source] = 1; //mark it visited;
        q.push(source);

        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(int i : graph[f]){
                if(!visited[i]){
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        return visited;
    }
};