class Solution {
public:
    int ans = 0;
    void dfs(int src,vector<vector<int>>& adj,int k,vector<int>& informTime){
        if(adj[src].size()==0)
        {
            ans = max(ans,k);
            return;
        }
        ans = max(ans,k);
        for(auto x:adj[src]){
            dfs(x,adj,k+informTime[x],informTime);
        }
        
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1)
            return 0;
        if(n==2)
            return 1;
        vector<vector<int>> adj(n);
        int i,src;
        for(i=0;i<n;i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
            else
                src=i;
        }
        dfs(src,adj,informTime[src],informTime);
        return ans;
    }
};
