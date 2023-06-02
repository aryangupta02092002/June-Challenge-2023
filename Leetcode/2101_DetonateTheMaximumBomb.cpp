class Solution {
public:
    #define ll long long
    
    void dfs(int src, vector<int> &vis, vector<int> adj[]){
        vis[src] = 1;
        for(int x : adj[src]){
            if(vis[x] == 0){
                dfs(x, vis, adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int sz = bombs.size();
        vector<int> adj[sz];

        for(int i=0; i<sz; i++){
            ll x1 = bombs[i][0];
            ll y1 = bombs[i][1];
            ll r1 = bombs[i][2];

            for(int j=0; j<sz; j++){
                if(i != j){
                    ll x2 = bombs[j][0];
                    ll y2 = bombs[j][1];
                    ll r2 = bombs[j][2];

                    ll dsq = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

                    if(dsq <= r1 * r1){
                        adj[i].push_back(j);
                    }
                }
            }
        }

        vector<int> vis(sz);
        int ans = 0;

        for(int i=0; i<sz; i++){
            dfs(i, vis, adj);
            int count = 0;

            for(int j=0; j<sz; j++){
                if(vis[j] == 1){
                    count++;
                }
            }

            ans = max(ans, count);
            fill(vis.begin(), vis.end(), 0);
        }
        return ans;
    }
};
