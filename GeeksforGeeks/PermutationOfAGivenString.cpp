//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void perm(set<string>&ans, int l, int h, string curr){
        if(l > h){
            ans.insert(curr);
            return;
        }
        for(int i=l; i<=h; i++){
            swap(curr[i], curr[l]);
            perm(ans, l+1, h, curr);
            swap(curr[i], curr[l]);
        }
    }
    vector<string>find_permutation(string S){
        set<string> ans;
        int n = S.size();
        perm(ans, 0, n-1, S);
        vector<string> t;
        
        for(auto x : ans)
            t.push_back(x);
        return t;
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
