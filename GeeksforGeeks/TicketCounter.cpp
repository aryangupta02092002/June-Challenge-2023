//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        int flag = 0, i = 1, j = N, l;
        
        while(i <= j)
        {
            if(flag == 0){
                if(i+K-1 <= j){
                    l = i+K-1;
                    i = i+K;
                    flag = 1;
                    continue;
                }
                else
                    K--;
            }
            else{
                if(j-K+1 >= i){
                    l = j-K+1;
                    j = j-K;
                    flag = 0;
                }
                else
                    K--;
            }
        }
        return l;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
