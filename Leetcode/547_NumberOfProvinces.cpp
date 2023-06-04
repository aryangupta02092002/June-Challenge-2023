class Solution {
public:
    
    void dfs(int curr, vector<vector<int>> &adj, vector<bool> &vis){
        vis[curr] = 1;
        for(int i=0; i<adj[curr].size(); i++){
            if(vis[i] == 0 && adj[curr][i] == 1){
                dfs(i, adj, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int sz = isConnected.size();
        vector<bool> vis(sz, 0);
        int count = 0;
        
        for(int i=0; i<sz; i++){
            if(!vis[i]){
                count++;
                dfs(i, isConnected, vis);
            }
        }
        
        return count;
    }
};
