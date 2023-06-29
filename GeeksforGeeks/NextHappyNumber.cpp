//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool ishappy(int n){
        if(n < 10)
            return (n==1 || n==7) ? 1:0;
        int num = 0;
        while(n){
            num += (n%10) * (n%10);
            n /= 10;
        }
        return ishappy(num);
    }
    int nextHappy(int n){
        for(int i=n+1; ; i++){
            if(ishappy(i))
                return i;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
