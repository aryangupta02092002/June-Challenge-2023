//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        map<int, int> m;
        vector<int> index;
        
        for(int i=0; i<row; i++){
            int num = 0;
            for(int j=0; j<col; j++)
            {
                num = num*10 + M[i][j];
            }
            if(m[num] == 0)
            {
                m[num]++;
                index.push_back(i);
            }
        }
        
        vector<vector<int>> ans(index.size());
        
        for(int i=0; i<index.size(); i++){
            for(int j=0; j<col; j++)
            {
                ans[i].push_back(M[index[i]][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends
