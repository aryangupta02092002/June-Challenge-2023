//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
    {
        //code here.
        stack<pair<int, char>> st;
        int n = s.size();
        for(int i=0; i<n; i++){
            int num = 0;
            while(i<n and isdigit(s[i])){
                num = num*10 + s[i]-'0';
                i++;
            }
                
            st.push({num, 'n'});
            st.push({i, 'i'});
        }
            
        string ans = "";
        while(!st.empty()){
            pair<int, char> p = st.top();
            st.pop();
                
            if(p.second == 'n')
                ans += to_string(p.first);
            else 
                ans += s[p.first];
        }
        return ans;    
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
