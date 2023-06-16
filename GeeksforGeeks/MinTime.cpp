//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    typedef long long ll;
    ll dp[100001][2];

    ll helper(ll idx,vector<vector<ll>>& nums,ll val){
        if(idx==nums.size()){
            if(val==1){
                return abs(nums[idx-1][1]);
            }
            else 
                return abs(nums[idx-1][2]);
        }
        if(dp[idx][val] != -1) 
            return dp[idx][val];
        ll prev=0;

        if(idx==0){
            prev=0;
        }
        else if(val==1){
            prev = nums[idx-1][1];
        }
        else{
            prev = nums[idx-1][2];
        }
        
        // This consider all the values of each type
        ll left = abs(nums[idx][2]-prev) + abs(nums[idx][1] - nums[idx][2]);
        ll right = abs(nums[idx][1]-prev) + abs(nums[idx][2] - nums[idx][1]);
        
        ll res;
        res = min({left + helper(idx+1, nums, 1), right + helper(idx+1, nums, 0)});
        return dp[idx][val] = res;
    }


    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        memset(dp,-1,sizeof(dp));
        map<ll,vector<ll>> umap;
        
        for(int i=0; i<n; i++){
            umap[types[i]].push_back(locations[i]);
        }
        
        vector <vector<ll>> nums;
        for(auto i : umap){
            ll minVal = LLONG_MAX;
            ll maxVal = LLONG_MIN;
            
            for(auto j : i.second){
                minVal = min(minVal, j);
                maxVal = max(maxVal, j);
            }
            nums.push_back({i.first, minVal, maxVal});
        }
        return helper(0, nums, 0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
