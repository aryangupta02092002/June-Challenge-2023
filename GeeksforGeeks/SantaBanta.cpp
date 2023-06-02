//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<int> primes,is_prime;
    void precompute(){
        int N = 2000000;
        is_prime.resize(N);
        primes.clear();
        for(int i=0;i<N;i++)
            is_prime[i]=1;
        is_prime[1]=0;
        for(int i=2;i*i<N;i++){
            if(is_prime[i]){
                for(int j=i*i;j<N;j+=i){
                    is_prime[j]=0;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(is_prime[i])
                primes.push_back(i);
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &graph){
        if(m==0)
            return -1;
        vector<int> vis(n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int count=0;
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    count++;
                    for(int it: graph[node]){
                        if(!vis[it]){
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
                ans=max(ans,count);
            }
        }
        return primes[ans];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends
