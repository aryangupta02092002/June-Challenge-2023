class Solution {
public:
    int dx[8] = {-1, -1, 1, 1, 1, -1, 0, 0};
    int dy[8] = {-1, 1, 1, -1, 0, 0, 1, -1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        grid[0][0] = 1;
        int ans = 1;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x == n-1 && y == n-1){
                    return ans;
                }
                
                for(int k=0; k<8; k++){
                    int newx = x + dx[k];
                    int newy = y + dy[k];
                    
                    if(newx >= 0 && newy >= 0 && newx < n && newy < n && grid[newx][newy] == 0){
                        q.push({newx, newy});
                        grid[newx][newy] = 1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
